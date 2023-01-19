<?php
require_once("db.php");
session_start();

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

    $email = test_input($_POST["loginEmail"]);
    $emailRegex = '/^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/';
    if (!preg_match($emailRegex, $email)) 
    {
        $errors["email"] = "Invalid Email";
    }

    $password = test_input($_POST["password"]);
    $passwordRegex = "/^.{8}$/";
    if (!preg_match($passwordRegex, $password)) 
    {
        $errors["password"] = "Invalid Password";
    }

    if ($dataOK) 
    {
        try 
        {
            $db = new PDO($attr, $db_user, $db_pwd, $options);
            $query = "SELECT uID, username, email, avatar_url FROM Users WHERE email = '$email' && password = '$password'";
            $result = $db->query($query);
            
            if (!$result) 
            {
                $errors["Database Error"] = "Could not retrieve user information";
            } elseif ($row = $result->fetch()) 
            {
                $_SESSION['uID'] = $row['uID'];
                $_SESSION['username'] = $row['username'];
                $_SESSION['email'] = $row['email'];
                $_SESSION['avatar_url'] = $row['avatar_url'];
                $db = null;
                header("Location: jokelist.php");
                exit();
            } else 
            {
                $errors["Login Failed"] = "Email/Password Combination Does Not Exist";
            }

            $db = null;
        } catch (PDOException $e) 
        {
            throw new PDOException($e->getMessage(), (int)$e->getCode());
        }
    } 
    else 
    {
        $errors[] = "You entered a blank data while logging in.";
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
    <script type="text/javascript" src="js/eventHandlers.js"></script>
    <title>Login Page</title>
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
                <h1>Log In</h1>
                <form action="" method="post" class="auth-form" id="login-form">
                    <p>
                        <br/>
                        Email
                        <br/>
                        <input type="text" name="loginEmail" id="loginEmail"/>
                    </p>
                    <p id="error-text-loginEmail" class="error-text hidden">Email Format Is Not Correct</p>
                    <p>
                        Password
                        <br/>
                        <input type="password" name="password" id="loginPassword"/>
                        <br/>
                        <br/>
                        <br/>
                        <input type="submit" value="Log in"/>
                    </p>
                </form>
                <br/>
                <br/>
                <button onclick="window.location.href ='signup.php'"> Sign Up </button>
                <br/>
            </div>
        </div>
        <div class="sl-column-right"></div>
    </div>
    <div class="sl-row-bottom">
        <div class="sl-column-left"></div>
        <div class="sl-column-center"></div>
        <div class="sl-column-right"></div>
    </div>
    <script type="text/javascript" src="js/eventRegisterLogin.js"></script>
</body>

</html>
