<?php

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // echo "update request found..";
    if (isset($_POST["uid"])) {
        $file = fopen("data.csv", "r");
        $temp = fopen("temp", 'a');
        // first we need to go to the position where the data is located.
        $count = 1;
        echo "updating the request uid: " . $_POST['uid'] . "<br>";

        while (!feof($file)) {
            // Now we need to write down the 
            // $init_pos = ftell($file);
            // $data = fgets($file);
            // echo "reading line: " . $count . "<br>";
            // $final_pos = ftell($file)
            if ($count == $_POST['uid']) {
                $string = sprintf(
                    "%s,%s,%s,%s,%s\n",
                    $_POST["title"],
                    $_POST['author'],
                    $_POST['subject'],
                    $_POST['pages'],
                    $_POST['prices']
                );
                fgets($file);
                fwrite($temp, $string);
            } else {
                fwrite($temp, fgets($file));
            }
            $count++;
        }

        fclose($file);
        fclose($temp);
        unlink("data.csv");
        rename("temp", "data.csv");
    }
}

header("Location:index.php");
