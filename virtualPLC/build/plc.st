TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    _TMP_ADD10_OUT : UINT;
    _TMP_EQ13_OUT : BOOL;
    _TMP_SEL15_OUT : UINT;
    _TMP_AND7_OUT : BOOL;
  END_VAR

  _TMP_ADD10_OUT := ADD(COUNTER, 1);
  _TMP_EQ13_OUT := EQ(N, _TMP_ADD10_OUT);
  _TMP_SEL15_OUT := SEL(_TMP_EQ13_OUT, _TMP_ADD10_OUT, 0);
  COUNTER := _TMP_SEL15_OUT;
  _TMP_AND7_OUT := AND(_TMP_EQ13_OUT, TRIG);
  py_eval(TRIG := _TMP_AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


FUNCTION_BLOCK rand_generator
  VAR_INPUT
    IN : BOOL;
  END_VAR
  VAR
    M : BOOL;
    INIT : BOOL;
  END_VAR
  VAR_OUTPUT
    RANDOM : INT := 0;
    BOTTKO : INT := 0;
    BOTTOK : INT := 0;
  END_VAR

  IF INIT = 0 THEN
    {srand(time(NULL))}
    INIT := 1;
  END_IF;

  IF M = 0 AND IN = 1 THEN
    {int r = rand() % 10;
    SetFbVar(RANDOM,r)}
    IF RANDOM = 0 THEN
      {int bKo = 0;
      bKo = GetFbVar(BOTTKO);
      bKo++;
      SetFbVar(BOTTKO,bKo)}
    ELSE
      {int bOk = 0;
      bOk = GetFbVar(BOTTOK);
      bOk++;
      SetFbVar(BOTTOK,bOk)}
    END_IF;
  END_IF;
  M := IN;
END_FUNCTION_BLOCK

PROGRAM BeerFactory
  VAR
    InputSegnale : BOOL;
    SensorePosBott : BOOL;
    MotoreCarrello : BOOL;
    MotoreDistribuzione : BOOL;
    SensoreLimite : BOOL;
    NumeroMaxBott : INT := 32767;
    NumeroBott : INT := 0;
    NumeroRand : INT := 0;
    NumBottKo : INT := 0;
    NumBottOk : INT := 0;
    Count : BOOL;
  END_VAR
  VAR
    EsCarrello : TP;
    EsDistribu : TP;
    RestartCarrello : TP;
    ContatoreBott : CTU;
    rand_generator0 : rand_generator;
    R_TRIG1 : R_TRIG;
  END_VAR

  EsCarrello(IN := NOT(SensorePosBott) AND InputSegnale, PT := T#5s);
  MotoreCarrello := EsCarrello.Q;
  SensorePosBott := NOT(MotoreCarrello) AND InputSegnale;
  MotoreDistribuzione := NOT(MotoreCarrello) AND InputSegnale;
  EsDistribu(IN := NOT(MotoreCarrello) AND InputSegnale, PT := T#5s);
  SensoreLimite := EsDistribu.Q;
  RestartCarrello(IN := NOT(MotoreCarrello) AND NOT(SensoreLimite) AND InputSegnale, PT := T#1s);
  SensorePosBott := RestartCarrello.Q;
  R_TRIG1(CLK := RestartCarrello.Q);
  ContatoreBott(CU := R_TRIG1.Q, PV := NumeroMaxBott);
  Count := ContatoreBott.Q;
  NumeroBott := ContatoreBott.CV;
  rand_generator0(IN := RestartCarrello.Q);
  NumeroRand := rand_generator0.RANDOM;
  NumBottKo := rand_generator0.BOTTKO;
  NumBottOk := rand_generator0.BOTTOK;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : BeerFactory;
  END_RESOURCE
END_CONFIGURATION
