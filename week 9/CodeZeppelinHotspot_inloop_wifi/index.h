R"(
<!DOCTYPE html>
<html lang="en">

<head>

  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1.0, minimum-scale=1.0, user-scalable=no">
  <meta name="description" content="FAB BLIMP RC CONTROL FAB LAB CONFERENCE 15">
  <meta name="author" content="Eduardo Chamorro Martin -eduardochamorromartin@gmail.com">

  <title>Awesome Machines Battle</title>

   <!-- Bootstrap core JavaScript -->
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
  <script> function makeAjaxCall(url){$.ajax({"url": url})}</script>
  <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.bundle.min.js"></script>
  <style>
   body {
     background-color: #03a9f4;
   }
   h1  {
     color: #000000;
      text-align: center;
      text-transform: uppercase;
      font-size: 55px;
      font-family: Raleway, "Open Sans", sans-serif;
      font-weight: 700;

   }
   h2  {
     color: #ffffff;
      text-align: center;
      text-decoration: underline;
      font-size: 35px;
      font-family: Raleway, "Open Sans", sans-serif;
      font-weight: 700;
   }
   p  {
     color: #000000;
      text-align: center;
      font-size: 25px;
      font-family: Raleway, "Open Sans", sans-serif;
      font-weight: 700;
   }
     img {
    display: block;
    margin-left: auto;
    margin-right: auto;

   }
   .column {
     float: left;
     width: 33.33%;
   }

   /* Clear floats after the columns */
   .row:after {
     content: "";
     display: table;
     clear: both;
   }

   .button {
        background-color: #ffffff;
        border: 5px solid #ffc107; /* Green border */
        border-radius: 12px;
        color: #ffc107; /* White text */
        padding: 10px 24px; /* Some padding */

        font-size: 35px;
        font-family: Raleway, "Open Sans", sans-serif;
        font-weight: 700;
 }

  </style>



</head>

<body id="page-top">

  <!-- Masthead -->
  <header class="masthead bg-primary text-white text-center">
    <div class="container d-flex align-items-center flex-column">

      <!-- Masthead Avatar Image -->

      <img class="masthead-avatar mb-5" src="https://i.imgur.com/SDeN29V.gif" width="100" height="100" alt=""  vspace="50">

      <!-- Masthead Heading -->
      <h1 class="masthead-heading text-uppercase mb-0">TEAM BLUE</h1>
      <div class="divider-custom divider-light">
        <div class="divider-custom-line"></div>
        <div class="divider-custom-icon">
          <i class="fas fa-star"></i>
        </div>
        <div class="divider-custom-line"></div>
      </div>

      <!-- Masthead Subheading -->
      <p class="masthead-subheading font-weight-light mb-0">Awesome Machines Battle</p>

    </div>
  </header>



      <!-- ControlZoneStartsHere -->
    <div class="container">
      <h2 class="page-section-heading text-center text-uppercase text-secondary mb-0">Blimp Control</h2>
        <div class="divider-custom">
          <div class="divider-custom-line"></div>
          <div class="divider-custom-icon">
            <i class="fas fa-star"></i>
          </div>
          <div class="divider-custom-line"></div>
        </div>
    </div>


<div class="container-fluid">
 <div class="row">

        <!-- ButtonACTION -->
        <div class="column">
            <button id="action" type="button" class="button" style="height: 100%; width: 100%" onmousedown='makeAjaxCall("action")' onmouseup='makeAjaxCall("ActionStop")' ontouchstart='makeAjaxCall("action")' ontouchend='makeAjaxCall("actionStop")'>ACTION</button>
        </div>

        <!-- ButtonLEFT -->
        <div class="column">
            <button id="left" type="button" class="button" style="height: 100%; width: 100%" onmousedown='makeAjaxCall("left")' onmouseup='makeAjaxCall("driveStop")' ontouchstart='makeAjaxCall("left")' ontouchend='makeAjaxCall("driveStop")'>LEFT</button>
        </div>

        <!-- ButtonRIGHT -->
        <div class="column">
           <button id="right" type="button" class="button" style="height: 100%; width: 100%" onmousedown='makeAjaxCall("right")' onmouseup='makeAjaxCall("driveStop")' ontouchstart='makeAjaxCall("right")' ontouchend='makeAjaxCall("driveStop")'>RIGHT</button>
        </div>

        <!-- ButtonFRONT -->

        <div class="column">
           <button id="front" type="button" class="button" style="height: 100%; width: 100%" onmousedown='makeAjaxCall("front")' onmouseup='makeAjaxCall("driveStop")' ontouchstart='makeAjaxCall("front")' ontouchend='makeAjaxCall("driveStop")'>FRONT</button>
        </div>

        <!-- ButtonPIVOTLEFT -->
        <div class="column">
            <button id="pivotleft" type="button" class="button" style="height: 100%; width: 100%" onmousedown='makeAjaxCall("pivotleft")' onmouseup='makeAjaxCall("driveStop")' ontouchstart='makeAjaxCall("pivotleft")' ontouchend='makeAjaxCall("driveStop")'>PIVOTLEFT</button>
        </div>


        <!-- ButtonBACK -->

        <div class="column">
           <button id="back" type="button" class="button" style="height: 100%; width: 100%" onmousedown='makeAjaxCall("back")' onmouseup='makeAjaxCall("driveStop")' ontouchstart='makeAjaxCall("back")' ontouchend='makeAjaxCall("driveStop")'>BACK</button>
        </div>

        <!-- ButtonPIVOTRIGHT -->
        <div class="column">
           <button id="pivotright" type="button" class="button" style="height: 100%; width: 100%" onmousedown='makeAjaxCall("pivotright")' onmouseup='makeAjaxCall("driveStop")' ontouchstart='makeAjaxCall("pivotright")' ontouchend='makeAjaxCall("driveStop")'>PIVOTRIGHT</button>
        </div>


 </div>
 </div>



  <!-- Copyright Section -->
  <section class="copyright py-4 text-center text-white">
    <div class="container">
      <small>Copyright &copy; Iaac - FabLab Barcelona 2019</small>
      <small>Developped by Eduardo Chamorro Martin and Santi Fuentemilla</small>
    </div>
  </section>


  <!--<script>
     document.addEventListener('keydown', function(event) {
        if(event.keyCode == 37) {
            //Left Arrow
            makeAjaxCall("left");
        }
        else if(event.keyCode == 39) {
            //Right Arrow
            makeAjaxCall("right");
        } else if(event.keyCode == 38) {
            //Up Arrow
            makeAjaxCall("up");
        } else if(event.keyCode == 40) {
            //Down Arrow
            makeAjaxCall("back");
        }
    });

    document.addEventListener('keyup', function(event) {
        if(event.keyCode == 37 ||event.keyCode == 39 ||event.keyCode == 40 ) {
            //Left or Right Arrow
            makeAjaxCall("steerStop");
        }
        else if(event.keyCode == 38  ) {
            //Up or Down Arrow
            makeAjaxCall("driveStop");
        }
    });
  </script>-->






</body>

</html>
)"
