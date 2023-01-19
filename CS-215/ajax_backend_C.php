<?php
require_once("db.php");

$jID = $_GET['jid'];

try {
    $db = new PDO($attr, $db_user, $db_pwd, $options);

    $query = "SELECT * FROM (SELECT Jokes.jID, Jokes.title, Jokes.created_DT, Jokes.text, Users.username, Users.avatar_url, AVG(Ratings.rating) as avgRating FROM Jokes LEFT JOIN Users ON Jokes.uID = Users.uID LEFT JOIN Ratings ON Jokes.jID = Ratings.jID GROUP BY Jokes.jID, Jokes.title, Jokes.created_DT, Jokes.text, Users.username, Users.avatar_url ORDER BY Jokes.created_DT Desc LIMIT 20) as T where jID > '$jID';";
    $result = $db->query($query);
    $jsonArray = array();
    while($row = $result->fetch())
    {
        array_push($jsonArray, $row);
    }
    echo json_encode($jsonArray);
    $db = null;

} catch (PDOException $e) {
    throw new PDOException($e->getMessage(), (int)$e->getCode());
}

$db = null; 
?>




