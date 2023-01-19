<?php
    require_once("db.php");
    session_start();
    
    if (!isset($_SESSION["uID"])) 
    {
      header("Location: login.php");
      exit();
    } 
    else 
    {
      $uID = $_SESSION["uID"];
      $username = $_SESSION["username"];
      $email = $_SESSION["email"];
      $avatar_url = $_SESSION["avatar_url"];
    }

    function test_input($data) 
    {
      $data = trim($data);
      $data = stripslashes($data);
      $data = htmlspecialchars($data);
      return $data;
    }
    
    if ($_SERVER["REQUEST_METHOD"] == "POST") 
    {
      $errors = array();
      $dataOK = TRUE;

      $title = test_input($_POST["joketitle"]);
      if (strlen($title) > 50 || strlen($title) < 1) 
      {
        $errors["title"] = "Title text size is not correct.";
        $dataOK = FALSE;
      }
  
      $text = test_input($_POST["joke"]);
      if (strlen($text) > 999 || strlen($text) < 1) 
      {
        $errors["joke"] = "Joke text size is not correct.";
        $dataOK = FALSE;
      }
  
      if ($dataOK) 
      {
          try 
          {
              $db = new PDO($attr, $db_user, $db_pwd, $options);
              $today = date("Y-m-d H:i:s");      
              $query = "INSERT INTO Jokes (uID, title, text, created_DT) VALUES('$uID', '$title', '$text', '$today')";
              $result = $db->exec($query);
              if (!$result) 
              {
                  $errors["Database Error"] = "Could Not Post The Joke";
              } 
              else 
              {
                $db = null;
                header("Location: jokelist.php");
                exit();
              } 
          }
          catch (PDOException $e) 
          {
            throw new PDOException($e->getMessage(), (int)$e->getCode());
          }
        }
        if(!empty($errors))
        {
          foreach($errors as $message) 
          {
              echo $message . "<br />\n";
          }
        }
      }
?>

<!DOCTYPE XHTML1.1>

<html lang="en" xmlns="http://www.w3.org/1999/xhtml">

<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
  <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <link rel="stylesheet" href="css/style.css"/>
  <script type="text/javascript" src="js/eventRegistersPostJoke.js"></script>
  <title> Post Joke Page </title>
</head>

<body>
  <div class="m-row-top">
    <div class="m-column-l-left"></div>
    <div class="m-column-c-left">
      <img class="page-logo" alt="logo" src="images/logo.png"/>
    </div>
    <div class="m-column-center">
      <h1> Post Joke Page </h1>
    </div>
    <div class="m-column-c-right">
      <h2 class="inline"> <?= $username ?> </h2>
      <img class="profile-logo" alt="profile" src="uploads/<?= $avatar_url ?>"/>
    </div>
    <div class="m-column-r-right"></div>
  </div>
  <div class="m-row-center">
    <div class="m-column-l-left"></div>
    <div class="m-column-c-left">
      <button onclick="window.location.href ='jokelist.php'"> Cancel Posting </button>
    </div>
    <div class="m-column-center">
      <form action="" method="post" class="auth-form" id="postjoke-form" enctype="multipart/form-data">
        <label for="jokeTitle">Joke Title</label>
        <br/>
        <input type="text" id="jokeTitle" name="joketitle"/>
        </p>
        <div id="countInput">
          <p>Letter Count: 0</p>
          <p>Remaining: 50</p>
        </div>
        <p>
          <br/>
          <br/>
          <label>Joke Text</label>
          <br/>
          <textarea id="jokeText" name="joke" rows="30" cols="20"></textarea>
          <br/>
          <br/>
          <br/>
          <button type="submit">Submit Joke</button>
        </p>
      </form>
    </div>
    <div class="m-column-c-right">
      <button onclick="window.location.href ='logout.php'"> Sign Out </button>
    </div>
    <div class="m-column-r-right"></div>
  </div>
  <div class="m-row-bottom">
    <div class="m-column-l-left"></div>
    <div class="m-column-c-left"></div>
    <div class="m-column-center"></div>
    <div class="m-column-c-right"></div>
    <div class="m-column-r-right"></div>
  </div>
</body>

</html>
