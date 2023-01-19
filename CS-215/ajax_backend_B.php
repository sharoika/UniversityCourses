<?php
require_once("db.php");

$jID = $_GET['jid'];

try {
    $db = new PDO($attr, $db_user, $db_pwd, $options);

    $query = "SELECT AVG(rating) as avgRating FROM Ratings WHERE jID = '$jID';";
    $result = $db->query($query);

    echo json_encode($result->fetch());
    $db = null;

} catch (PDOException $e) {
    throw new PDOException($e->getMessage(), (int)$e->getCode());
}

$db = null; 
?>




