# Java input Output

java I/O (input and output) is used to process the input and produce the output.

Java uses the concept of a stream to make I/O operation fast. the `java.io` package contains all the classes required for input and output operations.

we can perform file handling in java by Java I/O API.

## Stream

A stream is a sequence of data. in Java, a stream is composed of bytes. it's called a stream because it is like a stream of water that continues to flow.

1. System.out: standard output stream
2. System.in: standard input stream
3. System.err: standard error stream

**standard output stream**
```java
System.out.println("Hello World..!");
```

**standard err stream**
```java
System.err.println("Error: this is error...!");
```

**standard input stream**
```java
System.in.read(); // returns ASCII code of 1st character.
```

### Output Stream

Java application uses an output stream to write data to a destination; it may be a file, an array, peripheral device or socket.


### Input Stream

java application uses an input stream to read data from a source; it may be a file, an array, peripheral device or socket.

working flow of java input-output stream
<img style="background-color:white;" src="java-io-flow.png" alt="OutputStream">

### OutputStream class

OutputStream class is an abstract class. it is the superclass of all classes representing an output stream of bytes. An output stream accepts output bytes and sends them to some sink.

#### Useful methods of OutputStream

```java
public void write(int) throws IO Exception
/*
 * it is used to write a byte to the current output stream. 
 */

public void write(byte[]) throws IOException
/*
 * it is used to write an array of byte to the current output stream.
 */

public void flush() throws IOException
/*
 * flushes the current output stream.
 */

public void close() throws IOException
/*
 * It is used to close the current output stream.
 */
```
____
<br><br>

### InputStream class

InputStream class is an abstract class. it is the superclass of all classes representing an input stream of bytes.

#### Useful method of inputStream

```java
public abstract int read() throws IOException
/*
 * it reads the next byte of data from the input stream. it return -1 at the end of the file.
 */

public int available() throws IOException
/*
 * it returns an estimate of the number of bytes that can be read from the current input stream.
 */

public void close() throws IOException
/*
 * it is used to close the current input stream.
 */
```
____
<br><br>

## FileOutputStream Class

`FileOutputStream` is an output stream used for writing data to a file. if we have to primitive values into a file, we should use `FileOutputStream` class. we can write byte-oriented as well as character-oriented data through FileOutputStream class. But, for character-oriented data, it is preferred to use `FileWriter` than FileOutputStream.

FileOutputStream class methods

```java
protected void finalize()
/*
 * it is used to clean up the connection with the file output.
 */

void write(byte[] ary)
/*
 * it is used to write ary.length bytes from the byte array to the file output stream.
 */

void write(byte[] ary, int off, int len)
/*
 * it is used to write len bytes from the byte array starting at offset off to the file output stream.
 */

void write(int b)
/*
 * it is used to write the specified byte to the file output stream.
 */

FileChannel getChannel()
/*
 * It is used to return the file channel object associated with the file output stream.
 */

FileDescriptor getFD()
/*
 * It is used to return the file descriptor associated with the stream.
 */

void close()
/*
 * it is used to closes the file output stream.
 */
```
____
<br><br>
##  FileInputStream Class

java `FileInputStream` class obtain input bytes from a file. it is used for reading byte-oriented data (streams of raw bytes) such as image data, audio, video etc. we can also read character-stream data. 

Recommendation: we should use `FileReader` class to read the streams of characters.

```java
int available()
/*
 * it is used to return the estimated number of bytes that can be read from the input stream.
 */

int read()
/*
 * it is used to read the byte of data from the input stream.
 */

int read(byte[] b, int off, int len)
/*
 * It is used to read up to len bytes of data from the input stream.
 */

int read(byte[] b)
/*
 * It is used to read up to b.length bytes of data from the input stream.
 */

long skip(long x)
/*
 * It is used to skip over and discards x bytes of data from the input stream.
 */

FileChannel getChannel()
/*
 * It is used to return the unique FileChannel object associated with the file input stream.
 */

FileDescriptor getFD()
/*
 * It is used to return the FileDescriptor object.
 */

protected void finalize()
/*
 * 	It is used to ensure that the close method is call when there is no more reference to the file input stream.
 */

void close()
/*
 * it is used to closes the file input stream.
 */
```

<div class='note'>
<p> <b>Note:</b> FileInputStream and FileOutputStream both required the IOException handling so we need to use the try-catch block while working with the FileInputException and FileOutputException. </p>
</div>

____
<br><br>


## BufferedOutputStream Class

BufferedOutputStream class is used for buffering an output stream. it internally uses buffer to store data. it adds more efficiency than to write data directly into a stream. So, it makes the performance fast.

For adding the buffer in an OutputStream, use the BufferedOutputStream class. Syntax:
```java
OutputStream os= new BufferedOutputStream(new FileOutputStream(filename));  
```

BufferedOutputStream class constructor and methods:

```java
BufferedOutputStream(OutputStream os)
/*
 * It creates the new buffered output stream which is used for writing the data to the specified output stream.
*/

void write(int b)
/*
 * It writes the specified byte to the buffered output stream.
*/

void write(byte[] b, int off, int len)
/*
 * It write the bytes from the specified byte-input stream into a specified byte array, starting with the given offset
*/

void flush()
/*
 * It flushes the buffered output stream.
*/
```

## BufferedInputStream Class

BufferedInputStream class is used to read information form stream. it internally uses buffer mechanism to make the performance fast.

* When the bytes from the stream are skipped or read, the internal buffer automatically refilled from the contained input stream, many bytes at a time.

* When a BufferedInputStream is created, an internal buffer array is created. 

BufferedInputStream class constructor:

```java
BufferedInputStream(InputStream IS)
/*
 * It creates the BufferedInputStream and saves it argument, the input stream IS, for later use.
*/

BufferedInputStream(InputStream IS, int size)
/*
 * It creates the BufferedInputStream with a specified buffer size and saves it argument, the input stream IS, for later use.
*/

int available()
/*
 * It returns an estimate number of bytes that can be read from the input stream without blocking by the next invocation method for the input stream.
*/

int read()
/*
 * It read the next byte of data from the input stream.
*/

int read(byte[] b, int off, int ln)
/*
 *  It read the bytes from the specified byte-input stream into a specified byte array, starting with the given offset.
*/

void close()
/*
 * 	It closes the input stream and releases any of the system resources associated with the stream.
*/

void reset()
/*
 * It repositions the stream at a position the mark method was last called on this input stream.
*/

void mark(int readlimit)
/*
 * It sees the general contract of the mark method for the input stream.
*/

long skip(long x)
/*
 * 	It skips over and discards x bytes of data from the input stream.
*/

boolean markSupported()
/*
 * It tests for the input stream to support the mark and reset methods.
*/
```
____
<br><br>

## Java SequenceInputStream Class

A SequenceInputStream represent the logical concatenation of other input streams. It starts out with an ordered collection of input streams and reads form the first one until end of file is reached, whereupon it reads from the second one, and so on, until end of file is reached on the last of the contained input stream.

```java
SequenceInputStream(InputStream s1, InputStream s2)
/*
 * Initializes a newly created SequenceInputStream by remembering the two arguments, which will be read in order, first s1 and then s2 to provide the bytes to be read from this SequenceInputStream.
*/

SequenceInputStream(Enumeration<? extends InputStream> e)
/*
 * Initializes a newly created SequenceInputStream by remembering the argument, which must be an Enumeration that produces objects whose run-time type is InputStream.
*/

int available()
/*
 * Returns an estimate of the number of bytes that can be read (or skipped over) from the current underlying input stream without blocking by the next invocation of a method for the current underlying input stream.
*/

int read()
/*
 * Reads the next byte of data from this input stream..
*/

int read(byte[] b, int off, int ln)
/*
 *  It read the bytes from the specified byte-input stream into a specified byte arReads up to len bytes of data from this input stream into an array of bytes.
*/

void close()
/*
 * 	Closes this input stream and releases any system resources associated with the stream.
*/
```
_____
<br><br>

## ByteArrayOutputStream 

This class implement an output stream in which the data is written into a byte array. The buffer automatically grows as data is written to it. The data can be retrieved using toByteArray() and toString().

Closing a `ByteArrayOutputStream` has no effect. The methods in this class can be called after the stream has been closed without generating an IOException.

* ByteArrayOutputStream class is can be used to write common data into multiple files.
* The ByteArrayOutputStream holds a copy of data and forwards it to multiple streams.
* The buffer of ByteArrayOutputStream automatically grows according to data.

```java
ByteArrayOutputStream()
/*
 * Creates a new byte array output stream with the initial capacity of 32 bytes, though its size increases if necessary.
*/

ByteArrayOutputStream(int size)
/*
 * Creates a new byte array output stream, with a buffer capacity of the specified size, in bytes.
*/

int size()
/*
 * It is used to returns the current size of a buffer.
*/

byte[] toByteArray()
/*
 * It is used to create a newly allocated byte array.
*/

String toString()
/*
 *  It is used for converting the content into a string decoding bytes using a platform default character set.
*/

String toString(String charsetName)
/*
 * It is used for converting the content into a string decoding bytes using a specified charsetName.
*/

void write(int b)
/*
 * It is used for writing the byte specified to the ByteArrayOutputStream.
*/

void write(byte[] b, int off, int len
/*
 * It is used for writing len bytes from specified byte array starting from the offset off to the ByteArrayOutputStream.
*/

void writeTo(OutputStream out)
/*
 * It is used for writing the complete content of a byte array output stream to the specified output stream.
*/

void reset()
/*
 * It is used to reset the count field of a byte array output stream to zero value.
*/

void close()
/*
 * 	It is used to close the ByteArrayOutputStream.
*/
```