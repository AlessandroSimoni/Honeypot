void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->_TMP_ADD10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL15_OUT,0,retain)
  __INIT_VAR(data__->_TMP_AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,_TMP_EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,)));
  __SET_VAR(data__->,_TMP_SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->_TMP_SEL15_OUT,));
  __SET_VAR(data__->,_TMP_AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->_TMP_AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void RAND_GENERATOR_init__(RAND_GENERATOR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RANDOM,0,retain)
  __INIT_VAR(data__->BOTTKO,0,retain)
  __INIT_VAR(data__->BOTTOK,0,retain)
}

// Code part
void RAND_GENERATOR_body__(RAND_GENERATOR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->INIT,) == 0)) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
srand(time(NULL))
    #undef GetFbVar
    #undef SetFbVar
;
    __SET_VAR(data__->,INIT,,1);
  };
  if (((__GET_VAR(data__->M,) == 0) && (__GET_VAR(data__->IN,) == 1))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
int r = rand() % 10;
    SetFbVar(RANDOM,r)
    #undef GetFbVar
    #undef SetFbVar
;
    if ((__GET_VAR(data__->RANDOM,) == 0)) {
      #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
      #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
int bKo = 0;
      bKo = GetFbVar(BOTTKO);
      bKo++;
      SetFbVar(BOTTKO,bKo)
      #undef GetFbVar
      #undef SetFbVar
;
    } else {
      #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
      #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
int bOk = 0;
      bOk = GetFbVar(BOTTOK);
      bOk++;
      SetFbVar(BOTTOK,bOk)
      #undef GetFbVar
      #undef SetFbVar
;
    };
  };
  __SET_VAR(data__->,M,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // RAND_GENERATOR_body__() 





void BEERFACTORY_init__(BEERFACTORY *data__, BOOL retain) {
  __INIT_VAR(data__->INPUTSEGNALE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOREPOSBOTT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTORECARRELLO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTOREDISTRIBUZIONE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORELIMITE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->NUMEROMAXBOTT,32767,retain)
  __INIT_VAR(data__->NUMEROBOTT,0,retain)
  __INIT_VAR(data__->NUMERORAND,0,retain)
  __INIT_VAR(data__->NUMBOTTKO,0,retain)
  __INIT_VAR(data__->NUMBOTTOK,0,retain)
  __INIT_VAR(data__->COUNT,__BOOL_LITERAL(FALSE),retain)
  TP_init__(&data__->ESCARRELLO,retain);
  TP_init__(&data__->ESDISTRIBU,retain);
  TP_init__(&data__->RESTARTCARRELLO,retain);
  CTU_init__(&data__->CONTATOREBOTT,retain);
  RAND_GENERATOR_init__(&data__->RAND_GENERATOR0,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
}

// Code part
void BEERFACTORY_body__(BEERFACTORY *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->ESCARRELLO.,IN,,(!(__GET_VAR(data__->SENSOREPOSBOTT,)) && __GET_VAR(data__->INPUTSEGNALE,)));
  __SET_VAR(data__->ESCARRELLO.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
  TP_body__(&data__->ESCARRELLO);
  __SET_VAR(data__->,MOTORECARRELLO,,__GET_VAR(data__->ESCARRELLO.Q,));
  __SET_VAR(data__->,SENSOREPOSBOTT,,(!(__GET_VAR(data__->MOTORECARRELLO,)) && __GET_VAR(data__->INPUTSEGNALE,)));
  __SET_VAR(data__->,MOTOREDISTRIBUZIONE,,(!(__GET_VAR(data__->MOTORECARRELLO,)) && __GET_VAR(data__->INPUTSEGNALE,)));
  __SET_VAR(data__->ESDISTRIBU.,IN,,(!(__GET_VAR(data__->MOTORECARRELLO,)) && __GET_VAR(data__->INPUTSEGNALE,)));
  __SET_VAR(data__->ESDISTRIBU.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
  TP_body__(&data__->ESDISTRIBU);
  __SET_VAR(data__->,SENSORELIMITE,,__GET_VAR(data__->ESDISTRIBU.Q,));
  __SET_VAR(data__->RESTARTCARRELLO.,IN,,((!(__GET_VAR(data__->MOTORECARRELLO,)) && !(__GET_VAR(data__->SENSORELIMITE,))) && __GET_VAR(data__->INPUTSEGNALE,)));
  __SET_VAR(data__->RESTARTCARRELLO.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TP_body__(&data__->RESTARTCARRELLO);
  __SET_VAR(data__->,SENSOREPOSBOTT,,__GET_VAR(data__->RESTARTCARRELLO.Q,));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->RESTARTCARRELLO.Q,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->CONTATOREBOTT.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CONTATOREBOTT.,PV,,__GET_VAR(data__->NUMEROMAXBOTT,));
  CTU_body__(&data__->CONTATOREBOTT);
  __SET_VAR(data__->,COUNT,,__GET_VAR(data__->CONTATOREBOTT.Q,));
  __SET_VAR(data__->,NUMEROBOTT,,__GET_VAR(data__->CONTATOREBOTT.CV,));
  __SET_VAR(data__->RAND_GENERATOR0.,IN,,__GET_VAR(data__->RESTARTCARRELLO.Q,));
  RAND_GENERATOR_body__(&data__->RAND_GENERATOR0);
  __SET_VAR(data__->,NUMERORAND,,__GET_VAR(data__->RAND_GENERATOR0.RANDOM,));
  __SET_VAR(data__->,NUMBOTTKO,,__GET_VAR(data__->RAND_GENERATOR0.BOTTKO,));
  __SET_VAR(data__->,NUMBOTTOK,,__GET_VAR(data__->RAND_GENERATOR0.BOTTOK,));

  goto __end;

__end:
  return;
} // BEERFACTORY_body__() 





