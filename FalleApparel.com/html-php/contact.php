<!DOCTYPE html>
<html lang="en">
<head>
  <title>FΛLLΣ Apparel - Contact Us</title>
  <meta charset="UTF-8" />
  <meta name="author" content="Jonah Mamakeesic" />
  <meta name="description" content="The future is FΛLLΣ. Browse our newest products on FalleApparel.com" />
  <meta name="keywords" content="Falle, Falle Apparel, Victoria, BC, Canada, Jorden Falle, urban, luxury, fashion, apparel, casual, clothing" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <script src="../js/jquery.1.6.1.min.js"></script>
  <script src="../js/modernizr-1.5.js"></script>
  <script src="../js/simpleCart.js"></script>
  <link href="https://fonts.googleapis.com/css?family=Roboto+Condensed" rel="stylesheet">
  <link href="../css/styles.css" rel="stylesheet" type="text/css" />
  <link href="../css/mobile.css" rel="stylesheet" type="text/css" media="screen and (max-width: 799px)" />
  <link href="../css/contact.css" rel="stylesheet">
  <link rel="shortcut icon" href="../images/favicon.png">
</head>

<body>
  <!-- Menu bar section -->
  <header id="menubar"><table><tr>
    <td id="menu_l"><img id="dropmenu" src"../images/spacer.png" /></td>
    <td id="menu_c"><a href="../index.htm"><img id="logo_top" src="../images/logo24.png" alt="logo" /></a></td>
    <td id="menu_r"><a href="cart.htm"><img id="cart" src="../images/cart.png" alt="cart icon" />(<span id="simpleCart_quantity" class="simpleCart_quantity"></span>)</a></td>
    </tr></table></header>

  <!-- Fixed background image -->
  <div id="bgframe">
    <div id="bg"></div>
  </div>

  <!-- Header graphics -->
  <div id="topframe">
    <img id="model" src="../images/jorden.png" alt="" />
    <div id="logoframe">
      <h3>The future is</h3>
      <img id="logo" src="../images/logo_main.png" alt="Falle" />
    </div>
  </div>

  <!-- Content section -->
  <section class="content" id="first">
    <h1> Contact Us </h1>
    <div id="main">
      <div id="form_sample">

        <!-- Contact form -->
        <form action="" method="post">
          <label>Your Name: </label>
          <input type="text" name="name">
          <br />
          <label>Your Email: </label>
          <input type="text" name="email">
          <br />
          <label>Your Message: </label>
          <textarea name="msg"></textarea>
          <br />
          <input type="submit" name="submit" value="Submit">
        </form>
        <?php require "secure_email_code.php"; ?>

      </div>
    </div>
    <br />
  </section>

  <footer>
    <nav style="display:inline;">
      <a href="contact.php">Contact</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
      <a href="shipping.htm">Shipping</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
      <a href="returns.htm">Return&nbsp;Policy</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
      <a href="https://www.instagram.com/falleapparel/">
        <img class="social" src="../images/insta.png" height="25" alt="Instagram" />
      </a>
    </nav>
    <br />
    &copy;2018 FΛLLΣ Apparel
  </footer>

</body>
</html>
