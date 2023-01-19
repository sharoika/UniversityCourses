<?php
require_once("db.php");
session_start();

function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}

$username = "";
$password = "";
$email = ""; 
$dob = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") 
{
    $errors = array();
    $dataOK = TRUE;

    $username = test_input($_POST["username"]);
    $password = test_input($_POST["password"]);
    $cpassword = test_input($_POST["cpassword"]);
    $email = test_input($_POST["email"]);
    $dob = test_input($_POST["dob"]);;

    $unameRegex = "/^[a-zA-Z0-9_]+$/";
    $passwordRegex = "/^.{8}$/";
    $emailRegex = '/^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/';
    $dobRegex = "/^\d{4}[-]\d{2}[-]\d{2}$/";

    if (!preg_match($unameRegex, $username)) 
    {
        $errors["username"] = "Invalid Username";
        $dataOK = FALSE;
    }

    if (!preg_match($passwordRegex, $password)) 
    {
        $errors["password"] = "Invalid Password";
        $dataOK = FALSE;
    }

    if (!preg_match($emailRegex, $email)) 
    {
        $errors["email"] = "Invalid Email";
        $dataOK = FALSE;
    }

    if (!preg_match($dobRegex, $dob)) 
    {
        $errors["dob"] = "Invalid DOB";
        $dataOK = FALSE;
    }

    if ($password != $cpassword) 
    {
        $errors["passwords"] = "Passwords Dont Match";
        $dataOK = FALSE;
    }

    if ($dataOK) 
    {
        try 
        {
            $db = new PDO($attr, $db_user, $db_pwd, $options);
            $query = "SELECT count(*) FROM Users Where username = '$username' ";
            $result = $db->query($query);
            $matches = $result->fetchColumn();

            if ($matches == 0) 
            {
                $query = "INSERT INTO Users (username , password , email , dob, avatar_url) VALUES('$username', '$password','$email', '$dob', 'avatar_stub')";
                $result = $db->exec($query);
                if (!$result) 
                {
                    $errors["Database Error:"] = "Failed to insert user";
                } 
                else 
                {
                    $uploadOk = TRUE;
                    $target_dir = "uploads/";
                    $imageFileType = strtolower(pathinfo($_FILES["profilephoto"]["name"],PATHINFO_EXTENSION));
                    $uid = $db->lastInsertId();
                    $target_file = $target_dir . $uid . "." . $imageFileType;
                    $target_file_nodir = $uid . "." . $imageFileType;

                    if (file_exists($target_file)) 
                    {
                        $errors["profilephoto"] = "Sorry, file already exists. ";
                        $uploadOk = FALSE;
                    }

                    if ($_FILES["profilephoto"]["size"] > 1000000) 
                    {
                        $errors["profilephoto"] = "File is too large. Maximum 1MB. ";
                        $uploadOk = FALSE;
                    }

                    if($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg" && $imageFileType != "gif" ) 
                    {
                        $errors["profilephoto"] = "Bad image type. Only JPG, JPEG, PNG & GIF files are allowed. ";
                        $uploadOk = FALSE;
                    }

                    if ($uploadOk) {
                        $fileStatus = move_uploaded_file($_FILES["profilephoto"]["tmp_name"], $target_file);
                        if (!$fileStatus) {
                            $errors["Server Error"] = "There is a problem moving the file";
                            $query = "DELETE FROM Users WHERE username = '$username'";
                            $result = $db->exec($query);
                            if (!$result) {
                                $errors["Database Error"] = "could not delete user when avatar upload failed";
                            }
                            $db = null;
                        } else {
                            $query =  "UPDATE Users SET avatar_url = '$target_file_nodir' WHERE username = '$username'";
                            $result = $db->exec($query);
                            if (!$result) {
                                $errors["Database Error:"] = "could not update avatar_url";
                            } else {
                                $db = null;
                                header("Location: login.php");
                                exit();
                            }
                        }
                    }
                    else 
                    {
                        $query = "delete from Users where uID = '$uid';";
                        $result = $db->exec($query);
                        if (!$result) 
                        {
                            $errors["Delete Error:"] = "could not delete user";
                        } 
                        else 
                        {
                            $errors["Deleted:"] = "the user was deleted due to an error";
                        }
                    }
                }
            } 
            else 
            {
                $errors["Account Taken"] = "A user with that username already exists.";
            }
        } 
        catch (PDOException $e) 
        {
            die("Error: " . $e->getMessage());
        }
    }
    if (!empty($errors)) 
    {
        foreach($errors as $error => $message) 
        {
            print("$error: $message \n<br />");
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
    <script type="text/javascript" src="js/eventHandlers.js"></script>
    <title>Signup Page</title>
</head>

<body>
    <div class="sl-row-top">
        <div class="sl-column-left"></div>
        <div class="sl-column-center"></div>
        <div class="sl-column-right"></div>
    </div>
    <div class="sl-row-center">
        <div class="sl-column-left"></div>
        <div class="sl-column-center">
            <div class="box">
                <img id="login-logo" alt="logo" src="images/logo.png"/>
                <h1>Sign Up</h1>
                <form action="" method="post" class="auth-form" id="signup-form" enctype="multipart/form-data">
                    <p>
                        <label>Avatar</label>
                        <br/>
                        <input type="file" id="profilephoto" name="profilephoto" accept="image/*" />
                    </p>
                    <p id="error-text-profilephoto" class="error-text hidden">Profile Photo Is Not Correct</p>
                    <p>
                        <label>Username</label>
                        <br/>
                        <input type="text" name="username" id="signupUsername"/>
                    </p>
                    <p id="error-text-signupUsername" class="error-text hidden">Username Format Is Not Correct</p>
                    <p>
                        <label>Date of Birth (MM/DD/YYYY)</label>
                        <br/>
                        <input type="date" name="dob" id="signupDOB"/>
                    </p>
                    <p id="error-text-signupDOB" class="error-text hidden">DOB Format Is Not Correct</p>
                    <p>
                        <label>Email</label>
                        <br/>
                        <input type="text" name="email" id="signupEmail"/>
                    </p>
                    <p id="error-text-signupEmail" class="error-text hidden">Email Format Is Not Correct</p>
                    <p>
                        <label>Password</label>
                        <br/>
                        <input type="password" name="password" id="signupPassword"/>
                    </p>
                    <p id="error-text-signupPassword" class="error-text hidden">Password Format Is Not Correct</p>
                    <p>
                        <label>Confirm Password</label>
                        <br/>
                        <input type="password" name="cpassword" id="signupConfirmPassword"/>
                    </p>
                    <p id="error-text-signupConfirmPassword" class="error-text hidden">Passwords Do Not Match</p>
                    <p>
                        <br/>
                        <input type="submit" value="Sign Up"/>
                        <br/>
                    </p>
                </form>
                <br/>
                <br/>
                <button onclick="window.location.href ='login.php'"> Cancel </button>
            </div>
        </div>
        <div class="sl-column-right"></div>
    </div>
    <div class="sl-row-bottom">
        <div class="sl-column-left"></div>
        <div class="sl-column-center"></div>
        <div class="sl-column-right"></div>
    </div>
    <script type="text/javascript" src="js/eventRegisterSignup.js"></script>
</body>

</html>
