<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PHP Page 1</title>

    <style>
        table,
        th,
        td {
            border: 1px solid;
            border-collapse: collapse;
            padding: 2px 5px;
        }
    </style>

</head>

<?php

$data = [
    [
        "name" => "Gotam",
        "age" => 21,
        "height" => 5.6
    ],
    [
        "name" => "Suraj",
        "age" => 22,
        "height" => 5.7
    ],
    [
        "name" => "Narendra",
        "age" => 22,
        "height" => 5.5
    ],
    [
        "name" => "Manish",
        "age" => 27,
        "height" => 5.6
    ]

];

$keys = array_keys($data[0]);

?>

<body>

    <table>
        <thead>
            <tr>
                <?php foreach ($keys as $key) { ?>

                    <th><?= $key ?></th>

                <?php } ?>
            </tr>
        </thead>

        <tbody>

            <?php foreach ($data as $entry) { ?>

                <tr>
                    <?php foreach ($entry as $value) { ?>
                        <td><?= $value ?></td>
                    <?php } ?>
                </tr>

            <?php } ?>
        </tbody>
    </table>


</body>

</html>