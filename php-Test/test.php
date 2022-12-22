<?php
include "../php-Test/SQLUtility.php";


$permissions = [
    'r' => 'read-only',
    'r+' => 'read & write',
    'w' => 'write-only',
    'w+' => 'write & update',
    'w-' => 'delete'
];

show_array($permissions);

// now we will get key only.
show_array(array_keys($permissions));

echo join(",",array_keys($permissions))
?>