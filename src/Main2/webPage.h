/*


  OK, ya ready for some fun? HTML + CSS styling + javascript all in and undebuggable environment

  one trick I've learned to how to debug HTML and CSS code.

  get all your HTML code (from html to /html) and past it into this test site
  muck with the HTML and CSS code until it's what you want
  https://www.w3schools.com/html/tryit.asp?filename=tryhtml_intro

  No clue how to debug javascrip other that write, compile, upload, refresh, guess, repeat

  I'm using class designators to set styles and id's for data updating
  for example:
  the CSS class .tabledata defines with the cell will look like
  <td><div class="tabledata" id = "switch"></div></td>

  the XML code will update the data where id = "switch"
  java script then uses getElementById
  document.getElementById("switch").innerHTML="Switch is OFF";


  .. now you can have the class define the look AND the class update the content, but you will then need
  a class for every data field that must be updated, here's what that will look like
  <td><div class="switch"></div></td>

  the XML code will update the data where class = "switch"
  java script then uses getElementsByClassName
  document.getElementsByClassName("switch")[0].style.color=text_color;


  the main general sections of a web page are the following and used here

  <html>
    <style>
    // dump CSS style stuff in here
    </style>
    <body>
      <header>
      // put header code for cute banners here
      </header>
      <main>
      // the buld of your web page contents
      </main>
      <footer>
      // put cute footer (c) 2021 xyz inc type thing
      </footer>
    </body>
    <script>
    // you java code between these tags
    </script>
  </html>


*/

// note R"KEYWORD( html page code )KEYWORD"; 
// again I hate strings, so char is it and this method let's us write naturally

const char PAGE_MAIN[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="pt-br" class="js-focus-visible">

<title>THETA</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
  <style>
    html {
      font-family: "Lucida Console", Courier, monospace;
      text-align: center;  /* centralizando os botões dentro do quadro */
    }
    h1 {
      font-size: 1.8rem;  /*tamanho da fonte do cabeçalho "ESP WebSocket Server"**/
      color: white;       /*cor da fonte do cabeçalho "ESP WebSocket Server" */
    }
    .topnav {
      overflow: hidden;
      background-color: #7700c8; /*cor da moldura da inscrição "ESP WebSocket Server"*/
    }
    body {
      margin: 0;
    }
    .content {
      padding: 30px;     /*distância entre o título e o frame*/
      max-width: 600px;  /* largura da moldura*/
      margin: 0 auto;
    }
    .card {
      background-color: #F8F7F9; /* cor do quadro */
      box-shadow: 2px 2px 12px 1px rgba(140,140,140,.5);
      padding-top:10px;     /* recuo do primeiro botão até a borda superior do quadro */
      padding-bottom:20px;  /* recuo do último botão até a borda inferior do quadro*/
  }
    .button {
      padding: 8px 23px;  /*altura e largura do botão*/
      font-size: 24px;      /*tamanho da fonte do botão (o tamanho do botão se adapta ao tamanho da fonte)*/
      text-align: center;   /*centralizando o rótulo dentro do botão*/
      outline: none;
      color: #fff;                /*cor da fonte no botão*/
      background-color: #7700c8;   /*cor do botao*/
      border: none;
      border-radius: 5px;          /*raio dos cantos dos botões*/
      -webkit-touch-callout: none;
      -webkit-user-select: none;
      -khtml-user-select: none;
      -moz-user-select: none;
      -ms-user-select: none;
      user-select: none;
      -webkit-tap-highlight-color: rgba(0,0,0,0);
    }
    /*  button:hover {background-color: #6b0f8c} /* Cor de foco do botão */
    .button:active {
      background-color: #7700c8;
      box-shadow: 2 2px #7700c8;
      transform: translateY(2px);
    }
    .state {
      font-size: 1.0rem; /* tamanho da fonte do status do botão */
      color:#8c8c8c;    /* cor do botão ativo*/
      font-weight: bold;
    }
      
  </style>

  <body style="background-color: #efefef" onload="process()">

    <div class="topnav">
        <h1> Theta </h1>
    </div>


    <div class="sensorContent">
        <div class="card">
          <table align="center">
          <tr>
            <td colspan="3" align="center">
              <div class="card">
                <p class="card-title"> Distância Frente</p>
                <p class="reading"><span id="U"></span>cm</p>
              </div>
            </td>
          </tr>
          <tr>
            <td align="center">
              <div class="card">
                <p class="card-title"> Distância Esquerda</p>
                <p class="reading"><span id="humidity"></span></p>
              </div>
            </td>
            <td align="center">
              <img src="D:/Projetos/Theta/Programação\Theta/THETA/data/logo.png" alt="Theta Logo">
            </td>
            <td align="center">
              <div class="card">
                <p class="card-title"> Distância Direita</p>
                <p class="reading"><span id="humidity"></span> &percnt;</p>
              </div>
            </td>
          </tr>
          <tr>
            <td colspan="3" align="center">
              <div class="card">
                <p class="card-title"> Distância Atrás</p>
                <p class="reading"><span id="humidity"></span> &percnt;</p>
              </div>
            </td>
          </tr>
          </table>
        </div>
    </div>

    <div class="manualController">
      <div class="card">
        <table align="center">
          <tr>
            <td colspan="3" align="center">
              <button class="button" id="BTN_FRONT" onmousedown="BUTTON_PRESS_FRONT();" ontouchstart="BUTTON_PRESS_FRONT();" onmouseup="BUTTON_PRESS_STOP();" ontouchend="BUTTON_PRESS_STOP();">Forward</button>
            </td>
          </tr>
          <tr>
            <td align="center">
              <button class="button" onmousedown="BUTTON_PRESS_LEFT();" ontouchstart="BUTTON_PRESS_LEFT();" onmouseup="BUTTON_PRESS_STOP();" ontouchend="BUTTON_PRESS_STOP();">Left</button>
            </td>
            <td align="center">
              <button class="button" onmousedown="BUTTON_PRESS_STOP();" ontouchstart="BUTTON_PRESS_STOP();">Stop</button>
            </td>
            <td align="center">
              <button class="button" onmousedown="BUTTON_PRESS_RIGHT();" ontouchstart="BUTTON_PRESS_RIGHT();" onmouseup="BUTTON_PRESS_STOP();" ontouchend="BUTTON_PRESS_STOP();">Right</button>
            </td>
          </tr>
          <tr>
            <td colspan="3" align="center">
              <button class="button" onmousedown="BUTTON_PRESS_BACK();" ontouchstart="BUTTON_PRESS_BACK();" onmouseup="BUTTON_PRESS_STOP();" ontouchend="BUTTON_PRESS_STOP();">Backward</button>
            </td>
          </tr>
        </table>
      </div>
    </div>



  </body>


  <script type = "text/javascript">
  
    // global variable visible to all java functions
    var xmlHttp=createXmlHttpObject();

    // function to create XML object
    function createXmlHttpObject(){
      if(window.XMLHttpRequest){
        xmlHttp=new XMLHttpRequest();
      }
      else{
        xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
      }
      return xmlHttp;
    }

    // function to handle button press from HTML code above
    // and send a processing string back to server
    // this processing string is use in the .on method
    function BUTTON_PRESS_FRONT() {
      var xhttp = new XMLHttpRequest(); 
      var message;
      // if you want to handle an immediate reply (like status from the ESP
      // handling of the button press use this code
      // since this button status from the ESP is in the main XML code
      // we don't need this
      // remember that if you want immediate processing feedbac you must send it
      // in the ESP handling function and here
      /*
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          message = this.responseText;
          // update some HTML data
        }
      }
      */
       
      xhttp.open("PUT", "BUTTON_FRONT", false);
      xhttp.send();
    }


    function BUTTON_PRESS_STOP() {
      var xhttp = new XMLHttpRequest(); 
      var message;
      // if you want to handle an immediate reply (like status from the ESP
      // handling of the button press use this code
      // since this button status from the ESP is in the main XML code
      // we don't need this
      // remember that if you want immediate processing feedbac you must send it
      // in the ESP handling function and here
      /*
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          message = this.responseText;
          // update some HTML data
        }
      }
      */
       
      xhttp.open("PUT", "BUTTON_STOP", false);
      xhttp.send();
    }


    function BUTTON_PRESS_BACK() {
      var xhttp = new XMLHttpRequest(); 
      var message;
      // if you want to handle an immediate reply (like status from the ESP
      // handling of the button press use this code
      // since this button status from the ESP is in the main XML code
      // we don't need this
      // remember that if you want immediate processing feedbac you must send it
      // in the ESP handling function and here
      /*
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          message = this.responseText;
          // update some HTML data
        }
      }
      */
       
      xhttp.open("PUT", "BUTTON_BACK", false);
      xhttp.send();
    }

    function BUTTON_PRESS_RIGHT() {
      var xhttp = new XMLHttpRequest(); 
      var message;
      // if you want to handle an immediate reply (like status from the ESP
      // handling of the button press use this code
      // since this button status from the ESP is in the main XML code
      // we don't need this
      // remember that if you want immediate processing feedbac you must send it
      // in the ESP handling function and here
      /*
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          message = this.responseText;
          // update some HTML data
        }
      }
      */
       
      xhttp.open("PUT", "BUTTON_RIGHT", false);
      xhttp.send();
    }

    function BUTTON_PRESS_LEFT() {
      var xhttp = new XMLHttpRequest(); 
      var message;
      // if you want to handle an immediate reply (like status from the ESP
      // handling of the button press use this code
      // since this button status from the ESP is in the main XML code
      // we don't need this
      // remember that if you want immediate processing feedbac you must send it
      // in the ESP handling function and here
      /*
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          message = this.responseText;
          // update some HTML data
        }
      }
      */
       
      xhttp.open("PUT", "BUTTON_LEFT", false);
      xhttp.send();
    }



    // function to handle the response from the ESP
    function response(){
      var message;
      var xmlResponse;
      var xmldoc;

     
      // get the xml stream
      xmlResponse=xmlHttp.responseXML;
  
  
      //Mostrar a leitura do ULTRASSÔNICO NO SITE
      xmldoc = xmlResponse.getElementsByTagName("U"); //Ultrassonic
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById("U").innerHTML=message;


     }
  
    // general processing code for the web page to ask for an XML steam
    // this is actually why you need to keep sending data to the page to 
    // force this call with stuff like this
    // server.on("/xml", SendXML);
    // otherwise the page will not request XML from the ESP, and updates will not happen
    function process(){
     
     if(xmlHttp.readyState==0 || xmlHttp.readyState==4) {
        xmlHttp.open("PUT","xml",true);
        xmlHttp.onreadystatechange=response;
        xmlHttp.send(null);
      }       
        // you may have to play with this value, big pages need more porcessing time, and hence
        // a longer timeout
        setTimeout("process()",100);
    }
  
  
  </script>

</html>



)=====";