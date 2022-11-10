
<?php
$fh = fopen('employees.txt', 'r') or die("can't open: $php_errormsg");
$linebreak = $beginning_of_file = 0;
$gap = 80;
$filesize = filesize('employees.txt');
fseek($fh, 0, SEEK_END);

while (!($linebreak || $beginning_of_file)) {
    // save where we are in the file 
    $pos = ftell($fh);
    /* move back $gap chars, use rewind() to go to the beginning if * we're less 
    than $gap characters into the file */

    if ($pos < $gap) {
        rewind($fh);
    } else {
        fseek($fh, -$gap, SEEK_CUR);
    } // read the $gap chars we just seeked back over $s=fread($fh,$gap) or die($php_errormsg); 
    /* if we read to the end of the file, remove the last character * since if it's a newline, 
    we should ignore it */

    if ($pos + $gap >= $filesize) {
        $s = substr_replace($s, '', -1);
    } // move back to where we were before we read $gap chars into $s 

    if ($pos < $gap) {
        rewind($fh);
    } else {
        fseek($fh, -$gap, SEEK_CUR);
    }
    // is there a linebreak in ...
}
?>