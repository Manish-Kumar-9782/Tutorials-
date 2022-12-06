<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>getdate</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn about the `getdate` function. 
     * 
     * getdate: Get date/time information.
     *      
     *      Returns an associative array containing the date information of the `timestamp`
     *      or the current local time if `timestamp` is omitted or `null`.
     * 
     * Syntax:
     *      getdate(?int $timestamp = null): array
     * 
     * Parameters:
     *      
     *      timestamp:
     *          The optional `timestamp` parameter is an int Unix timestamp that default
     *          to the current local time if `timestamp` is omitted or null. In other words, 
     *          it defaults to the value of time().
     * 
     * Return: 
     *      Returns an associative array of information related to the timestamp. Elements 
     *      from the returned associative are as follows.
     * 
     * Errors/Exception:
     *      Every call to a date/time function will generate a E_WARNING if the time zone is not
     *      valid see also `date_default_time_zone()`.
     * 
     * Note: 
     *      Key elements of the returned associative array
     * 
     *      Key	Description     Example returned                            values
     *      "seconds"	        Numeric representation of seconds	        0 to 59
     *      
     *      "minutes"	        Numeric representation of minutes	        0 to 59
     *      
     *      "hours"	            Numeric representation of hours	            0 to 23
     *      
     *      "mday"	            Numeric representation of the 
     *                          day of the month	                        1 to 31
     *      
     *      "wday"	            Numeric representation of the day 
     *                          of the week	                                0 (for Sunday) through 6 (for Saturday)
     *      
     *      "mon"	            Numeric representation of a month	        1 through 12
     *      
     *      "year"	            A full numeric representation of a 
     *                          year, 4 digits	                            Examples: 1999 or 2003
     *      
     *      "yday"	            Numeric representation of the 
     *                          day of the year	                            0 through 365
     *      
     *      "weekday"	        A full textual representation of 
     *                          the day of the week	                        Sunday through Saturday
     *      
     *      "month"	            A full textual representation of 
     *                          a month, such as January or March	        January through December
     *      
     *      0	                Seconds since the Unix Epoch, similar 
     *                          to the values returned by time() and 
     *                          used by date().	                            System Dependent, typically -2147483648 through 2147483647.
     *
     * Format characters: 
     * 
     *      Day	---	---
     *          d:   Day of the month, 2 digits with leading zeros	01 to 31
     *          D:   A textual representation of a day, three letters	Mon through Sun
     *          j:   Day of the month without leading zeros	1 to 31
     *          l:   (lowercase 'L')	A full textual representation of the day of the week	Sunday through Saturday
     *          N:   ISO 8601 numeric representation of the day of the week	1 (for Monday) through 7 (for Sunday)
     *          S:   English ordinal suffix for the day of the month, 2 characters	st, nd, rd or th. Works well with j
     *          w:   Numeric representation of the day of the week	0 (for Sunday) through 6 (for Saturday)
     *          z:   The day of the year (starting from 0)	0 through 365
     * 
     *      Week	---	---
     *          W:	ISO 8601 week number of year, weeks starting on Monday	Example: 42 (the 42nd week in the year)
     *      
     *      Month	---	---
     *          F:	A full textual representation of a month, such as January or March	January through December
     *          m:	Numeric representation of a month, with leading zeros	01 through 12
     *          M:	A short textual representation of a month, three letters	Jan through Dec
     *          n:	Numeric representation of a month, without leading zeros	1 through 12
     *          t:	Number of days in the given month	28 through 31
     *      
     *      Year	---	---
     *          L:	Whether it's a leap year	1 if it is a leap year, 0 otherwise.
     *          o:	ISO 8601 week-numbering year. This has the same value as Y, except that if the ISO week number (W) belongs to the previous or next year, that year is used instead.	Examples: 1999 or 2003
     *          X:	An expanded full numeric representation of a year, at least 4 digits, with - for years BCE, and + for years CE.	Examples: -0055, +0787, +1999, +10191
     *          x:	An expanded full numeric representation if requried, or a standard full numeral representation if possible (like Y). At least four digits. Years BCE are prefixed with a -. Years beyond (and including) 10000 are prefixed by a +.	Examples: -0055, 0787, 1999, +10191
     *          Y:	A full numeric representation of a year, at least 4 digits, with - for years BCE.	Examples: -0055, 0787, 1999, 2003, 10191
     *          y:	A two digit representation of a year	Examples: 99 or 03
     *      
     *      Time	---	---
     *          a:	Lowercase Ante meridiem and Post meridiem	am or pm
     *          A:	Uppercase Ante meridiem and Post meridiem	AM or PM
     *          B:	Swatch Internet time	000 through 999
     *          g:	12-hour format of an hour without leading zeros	1 through 12
     *          G:	24-hour format of an hour without leading zeros	0 through 23
     *          h:	12-hour format of an hour with leading zeros	01 through 12
     *          H:	24-hour format of an hour with leading zeros	00 through 23
     *          i:	Minutes with leading zeros	00 to 59
     *          s:	Seconds with leading zeros	00 through 59
     *          u:	Microseconds. Note that date() will always generate 000000 since it takes an int parameter, whereas DateTime::format() does support microseconds if DateTime was created with microseconds.	Example: 654321
     *          v:	Milliseconds. Same note applies as for u.	Example: 654
     *      
     *      Timezone	---	---
     *          e:	Timezone identifier	Examples: UTC, GMT, Atlantic/Azores
     *          I: (capital i)	Whether or not the date is in daylight saving time	1 if Daylight Saving Time, 0 otherwise.
     *          O:	Difference to Greenwich time (GMT) without colon between hours and minutes	Example: +0200
     *          P:	Difference to Greenwich time (GMT) with colon between hours and minutes	Example: +02:00
     *          p:	The same as P, but returns Z instead of +00:00 (available as of PHP 8.0.0)	Examples: Z or +02:00
     *          T:	Timezone abbreviation, if known; otherwise the GMT offset.	Examples: EST, MDT, +05
     *          Z:	Timezone offset in seconds. The offset for timezones west of UTC is always negative, and for those east of UTC is always positive.	-43200 through 50400
     *      
     *      Full Date/Time	---	---
     *          c:	ISO 8601 date	2004-02-12T15:19:21+00:00
     *          r:	» RFC 2822/» RFC 5322 formatted date	Example: Thu, 21 Dec 2000 16:01:07 +0200
     *          U:	Seconds since the Unix Epoch (January 1 1970 00:00:00 GMT)	See also time()
     */
       </pre>

    <?php
    include "../Utility.php";
    /**
     * In this section we will learn about the `getdate` function. 
     * 
     * getdate: Get date/time information.
     *      
     *      Returns an associative array containing the date information of the `timestamp`
     *      or the current local time if `timestamp` is omitted or `null`.
     * 
     * Syntax:
     *      getdate(?int $timestamp = null): array
     * 
     * Parameters:
     *      
     *      timestamp:
     *          The optional `timestamp` parameter is an int Unix timestamp that default
     *          to the current local time if `timestamp` is omitted or null. In other words, 
     *          it defaults to the value of time().
     * 
     * Return: 
     *      Returns an associative array of information related to the timestamp. Elements 
     *      from the returned associative are as follows.
     * 
     * Errors/Exception:
     *      Every call to a date/time function will generate a E_WARNING if the time zone is not
     *      valid see also `date_default_time_zone()`.
     * 
     * Note: 
     *      Key elements of the returned associative array
     * 
     *      Key	Description     Example returned                            values
     *      "seconds"	        Numeric representation of seconds	        0 to 59
     *      
     *      "minutes"	        Numeric representation of minutes	        0 to 59
     *      
     *      "hours"	            Numeric representation of hours	            0 to 23
     *      
     *      "mday"	            Numeric representation of the 
     *                          day of the month	                        1 to 31
     *      
     *      "wday"	            Numeric representation of the day 
     *                          of the week	                                0 (for Sunday) through 6 (for Saturday)
     *      
     *      "mon"	            Numeric representation of a month	        1 through 12
     *      
     *      "year"	            A full numeric representation of a 
     *                          year, 4 digits	                            Examples: 1999 or 2003
     *      
     *      "yday"	            Numeric representation of the 
     *                          day of the year	                            0 through 365
     *      
     *      "weekday"	        A full textual representation of 
     *                          the day of the week	                        Sunday through Saturday
     *      
     *      "month"	            A full textual representation of 
     *                          a month, such as January or March	        January through December
     *      
     *      0	                Seconds since the Unix Epoch, similar 
     *                          to the values returned by time() and 
     *                          used by date().	                            System Dependent, typically -2147483648 through 2147483647.
     *
     * Format characters: 
     * 
     *      Day	---	---
     *          d:   Day of the month, 2 digits with leading zeros	01 to 31
     *          D:   A textual representation of a day, three letters	Mon through Sun
     *          j:   Day of the month without leading zeros	1 to 31
     *          l:   (lowercase 'L')	A full textual representation of the day of the week	Sunday through Saturday
     *          N:   ISO 8601 numeric representation of the day of the week	1 (for Monday) through 7 (for Sunday)
     *          S:   English ordinal suffix for the day of the month, 2 characters	st, nd, rd or th. Works well with j
     *          w:   Numeric representation of the day of the week	0 (for Sunday) through 6 (for Saturday)
     *          z:   The day of the year (starting from 0)	0 through 365
     * 
     *      Week	---	---
     *          W:	ISO 8601 week number of year, weeks starting on Monday	Example: 42 (the 42nd week in the year)
     *      
     *      Month	---	---
     *          F:	A full textual representation of a month, such as January or March	January through December
     *          m:	Numeric representation of a month, with leading zeros	01 through 12
     *          M:	A short textual representation of a month, three letters	Jan through Dec
     *          n:	Numeric representation of a month, without leading zeros	1 through 12
     *          t:	Number of days in the given month	28 through 31
     *      
     *      Year	---	---
     *          L:	Whether it's a leap year	1 if it is a leap year, 0 otherwise.
     *          o:	ISO 8601 week-numbering year. This has the same value as Y, except that if the ISO week number (W) belongs to the previous or next year, that year is used instead.	Examples: 1999 or 2003
     *          X:	An expanded full numeric representation of a year, at least 4 digits, with - for years BCE, and + for years CE.	Examples: -0055, +0787, +1999, +10191
     *          x:	An expanded full numeric representation if requried, or a standard full numeral representation if possible (like Y). At least four digits. Years BCE are prefixed with a -. Years beyond (and including) 10000 are prefixed by a +.	Examples: -0055, 0787, 1999, +10191
     *          Y:	A full numeric representation of a year, at least 4 digits, with - for years BCE.	Examples: -0055, 0787, 1999, 2003, 10191
     *          y:	A two digit representation of a year	Examples: 99 or 03
     *      
     *      Time	---	---
     *          a:	Lowercase Ante meridiem and Post meridiem	am or pm
     *          A:	Uppercase Ante meridiem and Post meridiem	AM or PM
     *          B:	Swatch Internet time	000 through 999
     *          g:	12-hour format of an hour without leading zeros	1 through 12
     *          G:	24-hour format of an hour without leading zeros	0 through 23
     *          h:	12-hour format of an hour with leading zeros	01 through 12
     *          H:	24-hour format of an hour with leading zeros	00 through 23
     *          i:	Minutes with leading zeros	00 to 59
     *          s:	Seconds with leading zeros	00 through 59
     *          u:	Microseconds. Note that date() will always generate 000000 since it takes an int parameter, whereas DateTime::format() does support microseconds if DateTime was created with microseconds.	Example: 654321
     *          v:	Milliseconds. Same note applies as for u.	Example: 654
     *      
     *      Timezone	---	---
     *          e:	Timezone identifier	Examples: UTC, GMT, Atlantic/Azores
     *          I: (capital i)	Whether or not the date is in daylight saving time	1 if Daylight Saving Time, 0 otherwise.
     *          O:	Difference to Greenwich time (GMT) without colon between hours and minutes	Example: +0200
     *          P:	Difference to Greenwich time (GMT) with colon between hours and minutes	Example: +02:00
     *          p:	The same as P, but returns Z instead of +00:00 (available as of PHP 8.0.0)	Examples: Z or +02:00
     *          T:	Timezone abbreviation, if known; otherwise the GMT offset.	Examples: EST, MDT, +05
     *          Z:	Timezone offset in seconds. The offset for timezones west of UTC is always negative, and for those east of UTC is always positive.	-43200 through 50400
     *      
     *      Full Date/Time	---	---
     *          c:	ISO 8601 date	2004-02-12T15:19:21+00:00
     *          r:	» RFC 2822/» RFC 5322 formatted date	Example: Thu, 21 Dec 2000 16:01:07 +0200
     *          U:	Seconds since the Unix Epoch (January 1 1970 00:00:00 GMT)	See also time()
     */
    ?>

    <?php
    heading(1, "Get Date/Time information");

    heading(2, "Today date: ");

    // Now we will get the today date by using the getdate();
    $today = getdate();
    show_array($today);

    put_sep();
    ?>

    <!-- timestamp date/time information. -->
    <?php
    // here we will use the mktime function to create a timestamp.
    $timestamp = mktime(12, 36, 12, 11, 19, 2022);

    // NOw we will get the the date/time information with getdate();
    $timestamp_info = getdate($timestamp);

    heading(3, "Other time stamp info: ");
    show_array($timestamp_info);
    ?>

    <!-- localtime information -->

    <?php
    // here we will use the mktime function to create a timestamp.
    $timestamp = localtime();

    // NOw we will get the the date/time information with getdate();

    heading(3, "Other time stamp info: ");
    show_array($timestamp);
    ?>



</body>

</html>