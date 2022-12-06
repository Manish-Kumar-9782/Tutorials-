<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>time</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn about the `time` function. 
     * 
     * localtime: Return current Unix timestamp.
     *       
     *      Returns the current time measured in the number of seconds since the Unix 
     *      Epoch (January 1 1970 00:00:00: GMT).
     * 
     * Syntax:
     *      time(): int
     * 
     * Parameters:
     *      
     *      No parameters...
     * 
     * Return: 
     *      Returns the current timestamp.
     * 
     * Errors/Exception:
     *      Every call to a date/time function will generate a E_WARNING if the time zone is not
     *      valid see also `date_default_time_zone()`.
     * 
     * Note: 
     *
     * Format characters: 
     <p>
     <h3>What is the Unix time stamp?</h3>
        The unix time stamp is a way to track time as a running total of seconds. 
        This count starts at the Unix Epoch on January 1st, 1970 at UTC. Therefore,
        the unix time stamp is merely the number of seconds between a particular 
        date and the Unix Epoch. It should also be pointed out (thanks to the 
        comments from visitors to this site) that this point in time technically 
        does not change no matter where you are located on the globe. This is very
        useful to computer systems for tracking and sorting dated information in
        dynamic and distributed applications both online and client side.</p>
     */ 
    </pre>
    <?php
    include "../Utility.php";
    /**
     * In this section we will learn about the `time` function. 
     * 
     * localtime: Return current Unix timestamp.
     *       
     *      Returns the current time measured in the number of seconds since the Unix 
     *      Epoch (January 1 1970 00:00:00: GMT).
     * 
     * Syntax:
     *      time(): int
     * 
     * Parameters:
     *      
     *      No parameters...
     * 
     * Return: 
     *      Returns the current timestamp.
     * 
     * Errors/Exception:
     *      Every call to a date/time function will generate a E_WARNING if the time zone is not
     *      valid see also `date_default_time_zone()`.
     * 
     * Note: 
     *
     * Format characters: 
     */
    ?>

    <?php
    heading(1, "Unix TimeStamps");

    heading(3, "Today Timestamps: ");

    // Now we will get the today date by using the getdate();
    $today_timestamp = time();

    $today_time = date("d-m-Y h:s:ia");
    display("pre", $today_time, 'data', "Today Unix timestamp time: ");
    put_sep();
    ?>






</body>

</html>