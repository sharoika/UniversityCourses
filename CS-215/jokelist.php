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

    try 
    {
      $db = new PDO($attr, $db_user, $db_pwd, $options);
    } 
    catch (PDOException $e) 
    {
      throw new PDOException($e->getMessage(), (int)$e->getCode());
    }

    $query = "SELECT Jokes.jID, Jokes.title, Jokes.created_DT, Jokes.text, Users.username, Users.avatar_url, AVG(Ratings.rating) as avgRating FROM Jokes LEFT JOIN Users ON Jokes.uID = Users.uID LEFT JOIN Ratings ON Jokes.jID = Ratings.jID GROUP BY Jokes.jID, Jokes.title, Jokes.created_DT, Jokes.text, Users.username, Users.avatar_url ORDER BY Jokes.created_DT Desc LIMIT 20;";
    $result = $db->query($query);
    $db = null; 
    
    if ($_SERVER["REQUEST_METHOD"] == "POST") 
    {
      $_SESSION['jID'] = $_POST['jID'];
      header("Location: jokedetail.php");
      exit();
    }
?>

<!DOCTYPE html>

<html lang="en" xmlns="http://www.w3.org/1999/xhtml">

<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
  <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <link rel="stylesheet" href="css/style.css"/>
  <script type="text/javascript" src="js/eventHandlers.js"></script>
  <title> Joke List Page </title>
</head>

<body>
  <div class="m-row-top">
    <div class="m-column-l-left"></div>
    <div class="m-column-c-left">
      <img class="page-logo" alt="logo" src="images/logo.png"/>
    </div>
    <div class="m-column-center">
      <div class="inner-row-2">
        <h1> Joke List Page </h1>
      </div>
      <div class="inner-row-2">
        <form action="jokelist.html" method="post" enctype="text/plain">
          <p>
          <input type="text"/>
          <button> Go </button>
          </p>
        </form>
      </div>
    </div>
    <div class="m-column-c-right">
      <h2 class="inline"> <?= $username ?> </h2>
      <img class="profile-logo" alt="profile" src="uploads/<?=$avatar_url?>"/>
    </div>
    <div class="m-column-r-right"></div>
  </div>
  <div class="m-row-center">
    <div class="m-column-l-left"></div>
    <div class="m-column-c-left">
      <button onclick="window.location.href ='postjoke.php'"> Post a Joke </button>
    </div>
    <div id="jokes"class="m-column-center">

    <?php
    while ($row = $result->fetch()) 
    {
        ?>
          <form name=<?= $row["jID"] ?>" method="post" class="auth-form" id="details<?= $row["jID"] ?>">
          <input type="hidden" id="jID" name="jID" value="<?= $row["jID"]?>">
          <input type="hidden" id="jID<?= $row["jID"]?>" name="jID" value="<?= $row["jID"]?>">

            <div class="joke" onclick="this.parentNode.submit();">

              <div class="joke-top-row">

                <div class="inline-left">
                  <h3> <?= $row["title"] ?> </h3>
                </div>

                <div class="inline-right">
                  <h4 class="inline"> By: <?= $row["username"] ?> </h4>
                  <img class="small-profile-logo" alt="profile" src="uploads/<?= $row["avatar_url"] ?>"/>
                </div>

              </div>

              <br>
              <br>

              <div class="joke-top-row">
                <div class="inline-right">
                  <h4 id="average_rating_<?=$row["jID"]?>"> Average Rating: <?= number_format(round($row["avgRating"], 2), 2) ?> </h4>
                </div>
              </div>

              <br>

              <div class="joke-bottom-row">
                <p class="joke-p"> <?=substr($row["text"], 0, 100)?> </p>
              </div>

              <div class="joke-bottom-row">
                <b class="joke-p"> <?= $row["created_DT"] ?></b>
              </div>

            </div>

          </form>
        <?php
    }
    ?>
    
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

<script type="text/javascript" src="js/eventRegisterJokeList.js"></script>

</html>
