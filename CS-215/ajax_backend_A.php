<?php
require_once("db.php");
session_start();

$rating = $_GET['rating'];
$uID = $_SESSION["uID"];
$jID = $_SESSION["jID"];

if ($rating > 5)
{
  $rating = 5; 
}
else if ($rating <= 0)
{
  $rating = 0;
}

try {
    $db = new PDO($attr, $db_user, $db_pwd, $options);

    $query = "SELECT * FROM Ratings WHERE jID = '$jID' AND uID = '$uID';";
    $result = $db->query($query);
    $matches = $result->fetchColumn();

    if ($matches != 0)
    {
      $query ="UPDATE Ratings SET rating = '$rating' WHERE jID = '$jID' && uID = '$uID';";
    }
    else
    {
      $query ="INSERT INTO Ratings (uID, jID, rating) VALUES ('$uID', '$jID', '$rating');";
    }

    $update = $db->exec($query);

    $query = "SELECT rating FROM Ratings WHERE jID = '$jID' AND uID = '$uID';";
    $result1 = $db->query($query);

    $query = "SELECT AVG(rating) as avgRating FROM Ratings WHERE jID = '$jID';";
    $result2 = $db->query($query);

    echo json_encode($result1->fetch() + $result2->fetch());
    $db = null;

} catch (PDOException $e) {
    throw new PDOException($e->getMessage(), (int)$e->getCode());
}

$db = null; 
?>





