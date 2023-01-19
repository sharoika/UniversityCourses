<?php
    require_once("db.php");
    session_start();
    
    if (!isset($_SESSION["uID"]) && !isset($_SESSION["jID"])) 
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
      $jID = $_SESSION["jID"];
    }

    try {
        $db = new PDO($attr, $db_user, $db_pwd, $options);
    } catch (PDOException $e) {
        throw new PDOException($e->getMessage(), (int)$e->getCode());
    }

    $query = "SELECT Ratings.rating FROM Users LEFT JOIN Ratings ON Users.uID = Ratings.uID LEFT JOIN Jokes ON Ratings.jID = Jokes.jID WHERE Jokes.jID = '$jID' && Users.uID = '$uID'; ";
    $rating = $db->query($query);
    $rating = $rating->fetch();

    $query = "SELECT Jokes.title, Jokes.text, Users.username, Users.avatar_url, AVG(Ratings.rating) as avgRating FROM Jokes LEFT JOIN Users ON Jokes.uID = Users.uID LEFT JOIN Ratings ON Jokes.jID = Ratings.jID WHERE Jokes.jID = '$jID' GROUP BY Jokes.title, Jokes.created_DT, Users.username, Users.avatar_url;";
    $result = $db->query($query);
    $row = $result->fetch();

    $db = null; 
?>

<!DOCTYPE html>

<html lang="en" xmlns="http://www.w3.org/1999/xhtml">

<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
  <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <link rel="stylesheet" href="css/style.css"/>
  <script type="text/javascript" src="js/eventHandlers.js"></script>
  <title>Joke Detail Page</title>
</head>

<body onload="">
  <div class="m-row-top">
    <div class="m-column-l-left"></div>
    <div class="m-column-c-left">
      <img class="page-logo" alt="logo" src="images/logo.png"/>
    </div>
    <div class="m-column-center">
      <h1> Joke Detail Page </h1>
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
      <button onclick="window.location.href ='jokelist.php'"> Return To Joke List </button>
    </div>
    <div class="m-column-center">
      <h2 class="joketitlegiven"> <?= $row["title"] ?> </h2>
      <p>
        <br/>
      </p>
      <h4 class="inline"> By: <?= $row["username"] ?> </h4>
      <p>
        <img class="profile-logo" alt="profile" src="uploads/<?= $row["avatar_url"] ?>" />
        <br/>
      </p>
      <h4 class="inline"> Average Rating: </h4> <h4 class="inline" id="average_rating"><?= round($row["avgRating"], 2) ?></h4>
      <div class="joke">
        <?= $row["text"] ?>
      </div>
        <div id="rating_location">
          <div>
            <input name="rating_input" id="rating_input" type="text" value=<?= $rating["rating"] ?? "N/A"?>>
          </div>
        </div>
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

<script type="text/javascript" src="js/eventRegisterJokeDetail.js"></script>

</html>
