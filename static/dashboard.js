document.addEventListener("DOMContentLoaded", function () {
    // Crea una variabile per memorizzare l'intervallo di aggiornamento
    var updateInterval;

    // Definisci una funzione per aggiornare i dati
    function updateContent() {
        // Invia una richiesta GET all'endpoint `/get_data`
        $.ajax({
            url: '/get_data',
            type: 'GET',
            success: function (data) {
                if (data[0] == true)
                    localStorage.setItem('statoFabbrica', "Accesa");
                else
                    localStorage.setItem('statoFabbrica', "Spenta");

                if (data[2] == true){
                    localStorage.setItem('sensoreLimite', "Raggiunto");
                    localStorage.setItem('sensorePosBott', "Nessun rilevamento");
                    localStorage.setItem('motoreCarrello', "In movimento");
                    localStorage.setItem('motoreDistribuzione', "Fermo");
                }
                else{
                    localStorage.setItem('sensorePosBott', "Rilevato");
                    localStorage.setItem('motoreCarrello', "Fermo");
                    if(data[3] == true){
                        localStorage.setItem('motoreDistribuzione', "In erogazione");
                        localStorage.setItem('sensoreLimite', "Non raggiunto");
                    }
                    else{
                        localStorage.setItem('motoreDistribuzione', "Fermo");
                    }
                }

                localStorage.setItem('numeroBott', data[5]);
                localStorage.setItem('numeroRand', data[6]);
                localStorage.setItem('numeroBottKo', data[7]);
                localStorage.setItem('numeroBottOk', data[8]);

                // Aggiorna gli elementi HTML con i nuovi dati
                $("#statoFabbrica").html("<span><b>Stato fabbrica:</b> " + localStorage.getItem('statoFabbrica') + "</span>");
                $("#sensorePosBott").html("<span><b>Sensore bottiglia:</b> " + localStorage.getItem('sensorePosBott') + "</span>");
                $("#motoreCarrello").html("<span><b>Motore carrello:</b> " + localStorage.getItem('motoreCarrello') + "</span>");
                $("#motoreDistribuzione").html("<span><b>Motore distribuzione:</b> " + localStorage.getItem('motoreDistribuzione') + "</span>");
                $("#sensoreLimite").html("<span><b>Sensore limite:</b> " + localStorage.getItem('sensoreLimite') + "</span>");
                $("#numeroBott").html("<span><b>Numero bottiglie:</b> " + localStorage.getItem('numeroBott') + "</span>");
                $("#numeroBottOk").html("<span><b>Numero bottiglie corrette:</b> " + localStorage.getItem('numeroBottOk') + "</span>");
                $("#numeroBottKo").html("<span><b>Numero bottiglie fallite:</b> " + localStorage.getItem('numeroBottKo') + "</span>");

                if (localStorage.getItem('numeroRand') == 0)
                    $("#circle").css("background-color", "red");
                else
                    $("#circle").css("background-color", "green");
            }
        });
    }

    // Avvia l'aggiornamento ogni tot tempo (ad esempio, ogni 5 secondi)
    updateInterval = setInterval(updateContent, 1000);

    // Controlla se c'è un valore memorizzato in localStorage
    var statoFabbricaValue = localStorage.getItem('statoFabbrica');
    var sensorePosBottValue = localStorage.getItem('sensorePosBott');
    var motoreCarrelloValue = localStorage.getItem('motoreCarrello');
    var motoreDistribuzioneValue = localStorage.getItem('motoreDistribuzione');
    var sensoreLimiteValue = localStorage.getItem('sensoreLimite');
    var numeroBottValue = localStorage.getItem('numeroBott');
    var numeroBottOkValue = localStorage.getItem('numeroBottOk');
    var numeroBottKoValue = localStorage.getItem('numeroBottKo');

    // Se esiste un valore in localStorage, utilizzalo
    if (statoFabbricaValue !== null) {
        $("#statoFabbrica").html("<span><b>Stato fabbrica:</b> " + statoFabbricaValue + "</span>");
        $("#sensorePosBott").html("<span><b>Sensore bottiglia:</b> " + sensorePosBottValue + "</span>");
        $("#motoreCarrello").html("<span><b>Motore carrello:</b> " + motoreCarrelloValue + "</span>");
        $("#motoreDistribuzione").html("<span><b>Motore distribuzione:</b> " + motoreDistribuzioneValue + "</span>");
        $("#sensoreLimite").html("<span><b>Sensore limite:</b> " + sensoreLimiteValue + "</span>");
        $("#numeroBott").html("<span><b>Numero bottiglie:</b> " + numeroBottValue + "</span>");
        $("#numeroBottOk").html("<span><b>Numero bottiglie corrette:</b> " + numeroBottOkValue + "</span>");
        $("#numeroBottKo").html("<span><b>Numero bottiglie fallite:</b> " + numeroBottKoValue + "</span>");
    }

    $("#start").click(function () {
        // Avvia l'aggiornamento ogni tot tempo (ad esempio, ogni 5 secondi)
        updateInterval = setInterval(updateContent, 1000);
    });

    // Ferma l'aggiornamento quando si clicca sul pulsante "stop"
    $("#stop").click(function () {
        clearInterval(updateInterval);
    });

    // Resetta il valore di numeroBott quando si clicca sul pulsante "reset"
    $("#reset").click(function () {
        localStorage.setItem('statoFabbrica', "Spenta");
        localStorage.setItem('sensorePosBott', "Nessun rilevamento");
        localStorage.setItem('motoreCarrello', "Fermo");
        localStorage.setItem('motoreDistribuzione', "Fermo");
        localStorage.setItem('sensoreLimite', "Non raggiunto");
        localStorage.setItem('numeroBott', 0);
        localStorage.setItem('numeroBottOk', 0);
        localStorage.setItem('numeroBottKo', 0);
        clearInterval(updateInterval);
    });
});