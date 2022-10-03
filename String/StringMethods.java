
class StringTests {

    public static void pritArray(String[] array) {
        System.out.print("[");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.print("]");
    };

    public static void String_charAt() {
        String line = "Hello this is string";

        // 1. charA(): it returns the value at the specified index number
        System.out.println("char at 7 " + line.charAt(7));
    }

    public static void String_compareTo() {
        // 2. compareTo(): it compare the given string with the current
        // string. returns positive, negative, zero.

        String s1 = "Apple";
        String s2 = "Boy";

        int result = s1.compareTo(s2);

        if (result == 0) {
            System.out.println("Both strings are equal");
        } else if (result == -1) {
            System.out.println("s1 is small to s2");
        } else if (result == 1) {
            System.out.println("s1 is greater to s2");
        }
    }

    public static void String_concat() {
        /*
         * concat() method combines specified string at the end of this string.
         * it returns a combined string.
         */

        String s1 = "Hello";
        String s2 = "World";

        // concatnating s1 and s2 strings.
        System.out.println("s1 string before concat: " + s1);
        // now s1 string has the s2 string also
        System.out.println("s1 string after concate: " + s1.concat(s2));
    }

    public static void String_contains() {
        /*
         * contains() method searches the sequence of characters in this string
         * 
         * Returns:
         * - true: if sequence is found
         * - false: if sequence is not found.
         * 
         * The contains() method should not be used to search for a
         * character in a string. Doing so results in an error.
         * 
         * The contains() method only checks for the presence or absence of
         * a string in another string. It never reveals at which index the
         * searched index is found. Because of these limitations, it is
         * better to use the indexOf() method instead of the contains()
         * method.
         */

        String str = "Hello this is the test of contains method of string.";

        // now we will use the contains on the str method.

        boolean result = str.contains("contains");

        if (result)
            System.out.println("match found");
        else
            System.out.println("match not found");
    }

    public static void String_endsWith() {
        /*
         * endsWith(): it test wether string ends with a substring.
         * 
         * true if the character sequence represented by the argument is a
         * suffix of the character sequence represented by this object;
         * false otherwise.
         * 
         * Note: that the result will be true if the argument
         * is the empty string or is equal to this String object as
         * determined by the equals(Object) method.
         */

        String str = "forExample@gmail.com";

        // now we will test that if above string endsWith .com or not.

        System.out.println("is .com present: " + str.endsWith(".com"));
    }

    public static void String_equals() {

        /*
         * equals(): it compare two string
         * 
         * Return:
         * - true: if all characters are matched.
         * - false: if any character is not match.
         */

        String s1 = "Hello";
        String s2 = "hello";

        System.out.println("is s1 equal to s2: " + s1.equals(s2));

    }

    public static void String_equalsIgnoreCase() {
        /*
         * equalsIgnoreCase() method compares two given string, in this we don't
         * consider the case sensitivity.
         * 
         * Return:
         * - true: if match found.
         * - false: if match not found.
         */

        String s1 = "Hello";
        String s2 = "hello";

        System.out.println("is s1 equal to s2: " + s1.equalsIgnoreCase(s2));
    }

    public static void String_format() {
        /*
         * format(): this method returns the formatted string by given, locale,
         * format and argument
         * 
         * if locale is not defined, it uses the Locale.getDefault()
         */
        float fnum = 10.123456f;
        System.out.println(String.format("float value: %.2f", fnum));
    }

    public static void String_getBytes() {
        /*
         * getBytes(): this method does the encoding of string into the sequence
         * of bytes and keeps it in an array of bytes.
         * 
         * we can define the charset to specify that, in which charset we want to
         * encode the string.
         * 
         * like: "UTF-16", "UTF-16BE", "ISO-8859-1" , "UTF-16LE"
         * 
         * Return: byte[]
         */

        String str = "Hello this is manish kumar";

        byte[] byte_string = str.getBytes();
        System.out.println(str + "in simple encoding:\n");
        for (int i = 0; i < byte_string.length; i++) {
            System.out.print(byte_string[i] + " ");
        }
    }

    public static void String_indexOf() {
        /*
         * indexOf(): get the index of the ch or substring from the given
         * string.
         */

        String str = "Hello this is java class.";
        int index = str.indexOf("java");
        System.out.println("index of java: " + index);
    }

    public static void String_intern() {
        /*
         * intern(): This method returns the interned string. it returns
         * the canonical representing of string.
         * 
         * Return:
         * a string that has the same contents as this string, but is
         * guaranteed to be from a pool of unique strings.
         */

        // Note: if we are creating the String object with new operator
        // without using the intern it will create a new memory allocation
        // for the same string.

        String strx1 = new String("Hello World");
        String strx2 = new String("Hello World");

        // Now we if test the strx1 and strx2 then it will return false.
        System.out.println("is strx1 & strx2 are equal: " + (strx1 == strx2));

        // Now if we use the intern() method on the String() constructor.
        // String().intern() it will return the existing reference for that
        // string

        String str1 = new String("New World").intern();
        String str2 = new String("New World").intern();
        System.out.println("is str1 & str2 are equal: " + (str1 == str2));
        // System.out.println;
    }

    public static void String_isEmpty() {
        /*
         * isEmpty(): This method checks the length of the string, if
         * length of the string is 0, it return true else flase.
         */

        String str1 = "Hello Wrold";
        String str2 = "";

        System.out.println("is str1 is empty string: " + str1.isEmpty());
        System.out.println("is str2 is empty string: " + str2.isEmpty());
    }

    public static void String_isBlank() {
        /*
         * isBlank(): This method test wether a string is empty of only
         * contains the whitespace.
         * 
         * Return:
         * true if the string is empty or contains only whitespace otherwise
         * false.
         */

        String str1 = "Hello World";
        String str2 = "";
        String str3 = "     ";

        // now we will use the isBlank() method.

        System.out.println("is str1 Blank: " + str1.isBlank());
        System.out.println("is str2 Blank: " + str2.isBlank());
        System.out.println("is str3 Blank: " + str3.isBlank());
    }

    public static void String_join() {
        /*
         * join(): This method joins the number of strings by using the specified
         * CharSequence delimiter
         * 
         * Delimiter: a character that marks the beginning or end of a unit of data.
         * 
         * Returns: A new string composed of copies of the CharSequence elements
         * joined together with a copy of the specified delimiter.
         */

        String array[] = { "Name", "age", "height", "bloodgroup" };
        // array of string with initalizer list.

        System.out.println("joined string: " + String.join(",", array));

        // Note here we can pass either an iterable object or we can pass
        // multiple string as the argument

        System.out.println("Time Format : " + String.join(":", "10", "25", "45"));
        System.out.println("Date Format : " + String.join("/", "10", "02", "2022"));

    }

    public static void String_LastIndexOf() {
        /*
         * LastIndexOf(): it returns the last index of the given character if
         * found, else will return -1
         */

        String str = "Hello this is core Java class.";
        String str2 = "Hello this is core Java class. This language is a very popular among the developer";

        System.out.println("last index of the 'i' in str: " + str.lastIndexOf("i"));
        System.out.println("last index of the 'is' in str2: " + str2.lastIndexOf("is"));

    }

    public static void String_length() {
        /*
         * length(): finds the length of a string.
         */

        String str = "Hello this is the sample string.";
        System.out.println("Length of the str string: " + str.length());
    }

    public static void String_replace() {

        /*
         * replace(): This method replace the all found char or char sequence
         * by new char or char sequence.
         */

        String str = "Hello, ary you moni. Hey moni nice to meet you.";

        System.out.println("Original string: " + str);
        System.out.println("replacing moni form string: " + str.replace("moni", "joni"));
    }

    public static void String_replaceAll() {

        /*
         * replaceAll(): This method replace the all matching regex char or char
         * sequence
         * by new char or char sequence.
         */

        String str = "Hello, ary you moni. Hey moni nice to meet you.";

        System.out.println("Original string: " + str);
        System.out.println("replacing moni form string: " + str.replaceAll("\\s", "-"));

    }

    public static void String_split() {
        /*
         * split(): This method is the inverse of join method. it splits the
         * string against the given regular expression.
         * 
         * Return: array of substrings.
         */

        // Note: if the regular expression is invalid it will throw
        // PatternSyntaxException.
        String str = "Name,age,height,bloodgroup";
        String time = "10:15:45";
        String date = "10/10/2020";

        String strx[] = str.split(",");
        String timex[] = time.split(":");
        String datex[] = date.split("/");

        System.out.print("\nOriginal: " + str + "\t" + "Splitted: ");
        pritArray(strx);
        System.out.print("\nOriginal: " + time + "\t" + "Splitted: ");
        pritArray(timex);
        System.out.print("\nOriginal: " + date + "\t" + "Splitted: ");
        pritArray(datex);

    }

    public static void String_startsWith() {
        /*
         * startsWith(): Tests if the string with the specified prefix.
         */

        String str = "com.heraPheri@gmail.org";
        System.out.println("is com present in domain: " + str.startsWith("com"));
    }

    public static void String_substring() {
        /*
         * substrings(): it Returns a string that is a substring of this string.
         */

        String str = "Hello this is Java Programming.";

        // In in this first we will find the java substring form that we will
        // return the substring until the end of the string.

        int jindex = str.indexOf("Java");

        String sub_str = str.substring(jindex);

        System.out.println("Whole String: " + str);
        System.out.println("Sub String: " + sub_str);
        // Note here we can define both the start and end index
        // values to set the range of the substring.
    }

    public static void String_toCharArray() {

        /*
         * toCharArray(): it converts a string into a character array.
         * 
         * Return: it returns a newly created character array.
         */

        String str = "Hello this is world";
        char char_arr[] = str.toCharArray();

        System.out.println("Char Array: ");
        for (int i = 0; i < char_arr.length; i++) {
            System.out.print(char_arr[i]);
        }
    }

    public static void String_toLowerCase() {
        /*
         * toLowerCase(): it return the string in the lowercase letter.
         */

        String str = "Hello World";
        String str2 = "HELLO WORLD";

        String str_lower = str.toLowerCase();
        String str2_lower = str2.toLowerCase();

        System.out.println("Original: " + str + "\t" + "toLowerCase: " + str_lower);
        System.out.println("Original: " + str2 + "\t" + "toLowerCase: " + str2_lower);
    }

    public static void String_toUpperCase() {
        /*
         * toLowerCase(): it return the string in the uppercase letter.
         */

        String str = "Hello World";
        String str2 = "hello world";
        String str_upper = str.toUpperCase();
        String str2_upper = str2.toUpperCase();

        System.out.println("Original: " + str + "\t" + "toUpperCase: " + str_upper);
        System.out.println("Original: " + str2 + "\t" + "toUpperCase: " + str2_upper);
    }

    public static void String_trim() {
        /*
         * trim(): this method eliminates leading and trailing spaces.
         * 
         * Note: The String.trim() method does not removes the internal space.
         * b/w the characters.
         */

        String str = "    hello  world -- 11   ";

        System.out.println("Original: " + str);
        System.out.println("Trimed: " + str.trim());
    }

    public static void String_valueOf() {
        /*
         * valueOf(): method converts different types of values into the string.
         * 
         * by using this, we can convert int, long, float, boolean, character, double,
         * object
         * 
         * to string.
         */

        int intNum = 10;
        float floatNum = 12.34f;
        double doubleNum = 243.342;
        short shortNum = 243;
        boolean boolNum = true;

        System.out.println(String.valueOf(intNum));
        System.out.println(String.valueOf(floatNum));
        System.out.println(String.valueOf(doubleNum));
        System.out.println(String.valueOf(shortNum));
        System.out.println(String.valueOf(boolNum));
    }
}

public class StringMethods {

    public static void main(String[] args) {
        // Now here we will run all the string method.\

        System.out.print("\033[H\033[2J");
        System.out.flush();

        // comparing the string
        // StringTests.String_compareTo();

        // concatnating the string.
        // StringTests.String_concat();

        // contians a sub string.
        // StringTests.String_contains();

        // endsWith a string.
        // StringTests.String_endsWith();

        // equals string
        // StringTests.String_equals();

        // equalsIgnoreCase a string
        // StringTests.String_equalsIgnoreCase();

        // formatted string
        // StringTests.String_format();

        // getByte string
        // StringTests.String_getBytes();

        // indexOf string
        // StringTests.String_indexOf();

        // intern method of string.
        // StringTests.String_intern();

        // isEmpty method of string.
        // StringTests.String_isEmpty();

        // isBlank method of string.
        // StringTests.String_isBlank();

        // join method of string
        // StringTests.String_join();

        // LastIndexOf method os string.
        // StringTests.String_LastIndexOf();

        // length method of string.
        // StringTests.String_length();

        // replace method of string
        // StringTests.String_replace();

        // replaceAll method of string
        // StringTests.String_replaceAll();

        // split method of string.
        // StringTests.String_split();

        // startsWith method of string.
        // StringTests.String_startsWith();

        // substring method of string.
        // StringTests.String_substring();

        // toCharArray method of string
        // StringTests.String_toCharArray();

        // toLowerCase method of string.
        // StringTests.String_toLowerCase();

        // toUpperCase method of string.
        // StringTests.String_toUpperCase();

        // trim method of string.
        // StringTests.String_trim();

        // valueOf method of string.
        StringTests.String_valueOf();

    }
}
