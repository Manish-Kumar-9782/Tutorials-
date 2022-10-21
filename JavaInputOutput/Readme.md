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

____
<br><br>

## ByteArrayInputStream

A `ByteArrayInputStream` contains an internal buffer that contains bytes that may be read from the stream. An internal counter keeps track of the next byte to be supplied by the read method.

Closing a `ByteArrayInputStream` has no effect. The methods in this class can be called after the stream has been closed without generating an IOException.

**known fields:**

* **`buf: (protected)`** An array of bytes that was provided by the creator of the stream. Elements `buf[0]` through `buf[count-1]` are the only bytes that can ever be read from the stream; element `buf[pos]` is the next byte to be read.

* **`pos: (protected)`** The index of the next character to read from the input stream buffer. This value should always be nonnegative and not larger than the value of count. the next byte to be read from the input stream buffer will be `buf[pos]`.

* **`mark: (protected)`**  The currently marked position in the stream ByteArrayInputStream objects are marked at tposition zero by default when constructed they may be marked at another position within the buffer by the mark() method. The current buffer position is set to this point by the reset() method.
  
  * if no mark has been set, then the value of mark is the offset passed to the constructor (or 0 if the offset was not supplied.)

* **`count: (protected)`** The index one greater than the last valid character in the input stream buffer. This value should always be nonnegative and not larger than the length of `buf`. it is one greater than the position of the last byte within `buf` that can ever be read from the input stream buffer. 

```java
ByteArrayInputStream(byte[] buf)
/*
 * Creates a ByteArrayInputStream so that it uses buf as its buffer array. The 
 * buffer array is not copied. The initial value of pos is 0 and the initial value
 *  of count is the length of buf.
*/

ByteArrayInputStream(byte[] buf,int offset,int length)
/*
 * Creates ByteArrayInputStream that uses buf as its buffer array. The initial value
 *  of pos is offset and the initial value of count is the minimum of offset+length
 *  and buf.length. The buffer array is not copied. The buffer's mark is set to the
 *  specified offset.
*/

int read()
/*
 * Reads the next byte of data from this input stream. The value byte is returned as
 * an int in the range 0 to 255. If no byte is available because the end of the stream 
 * has been reached, the value -1 is returned.
 * 
 * This read method cannot block.
*/

public int read(byte[] b,int off,int len)
/*
 * Reads up to len bytes of data into an array of bytes from this input stream. If 
 * pos equals count, then -1 is returned to indicate end of file. Otherwise, the 
 * number k of bytes read is equal to the smaller of len and count-pos. If k is 
 * positive, then bytes buf[pos] through buf[pos+k-1] are copied into b[off] through b
 * [off+k-1] in the manner performed by System.arraycopy. The value k is added into 
 * pos and k is returned.
 * 
 * Unlike the overridden method of InputStream, this method returns -1 instead of 
 * zero if the end of the stream has been reached and len == 0.
 * 
 * This read method cannot block.
*/

public byte[] readAllBytes()
/*
 *  Reads all remaining bytes from the input stream. This method blocks until all 
 *  remaining bytes have been read and end of stream is detected, or an exception is
 *  thrown. This method does not close the input stream.
 * 
 *  When this stream reaches end of stream, further invocations of this method will 
 *  return an empty byte array.
*/

public int readNBytes(byte[] b,int off,int len)
/*
 * Reads the requested number of bytes from the input stream into the given byte 
 * array. This method blocks until len bytes of input data have been read, end of 
 * stream is detected, or an exception is thrown. The number of bytes actually read,
 * possibly zero, is returned. This method does not close the input stream.
 * 
 * In the case where end of stream is reached before len bytes have been read, then
 * the actual number of bytes read will be returned. When this stream reaches end of 
 * stream, further invocations of this method will return zero.
 * 
*/

public long skip(long n)
/*
 * Skips n bytes of input from this input stream. Fewer bytes might be skipped if 
 * the end of the input stream is reached. The actual number k of bytes to be skipped 
 * is equal to the smaller of n and count-pos. The value k is added into pos and k is 
 * returned.
*/

public int available()
/*
 * Returns the number of remaining bytes that can be read (or skipped over) from 
 * this input stream.
 * 
 * The value returned is count - pos, which is the number of bytes remaining to be 
 * read from the input buffer.
*/

public boolean markSupported()
/*
 * Tests if this InputStream supports mark/reset.
*/

public void mark(int readAheadLimit)
/*
 * Set the current marked position in the stream. ByteArrayInputStream objects are 
 * marked at position zero by default when constructed. They may be marked at another
 * position within the buffer by this method.
 * 
 * If no mark has been set, then the value of the mark is the offset passed to the
 * constructor (or 0 if the offset was not supplied).
*/

public void reset()
/*
 * Resets the buffer to the marked position. The marked position is 0 unless another
 * position was marked or an offset was specified in the constructor.
*/

public void close() throws IOException
/*
 * 	Closing a ByteArrayInputStream has no effect. The methods in this class can be
 *  called after the stream has been closed without generating an IOException.
*/
```
____
<br><br>

## DataOutputStream

A data output stream lets an application write primitive java data types to an output stream in a portable way. An application can then use a data input stream to read the data back in.

A `DataOutputStream` is not safe for use by multiple concurrent threads. If a DataOutputStream is to be used by more than one thread then access to the data output stream should be controlled by appropriate synchronization.

```java
DataOutputStream(OutputStream out)
/*
 * Creates a new data output stream to write data to the specified underlying 
 * output stream.
*/

void flush()
/*
 * Flushes this data output stream.
*/

final int size()
/*
 * Returns the current value of the counter written, the number of bytes written 
 * to this data output stream so far.
*/

void write(byte[] b, int off, int len)
/*
 *  Writes len bytes from the specified byte array starting at offset off to the 
 *  underlying output stream.
*/

void write(int b)
/*
 * Writes the specified byte (the low eight bits of the argument b) to the
 * underlying output stream.
*/

final void writeBoolean(boolean v)
/*
 * Writes a boolean to the underlying output stream as a 1-byte value.
*/

final void writeByte(int v)
/*
 * Writes out a byte to the underlying output stream as a 1-byte value.
*/

final void writeBytes(String s)
/*
 * Writes out the string to the underlying output stream as a sequence of bytes.
*/

final void writeChar(int v)
/*
 * Writes a char to the underlying output stream as a 2-byte value, high byte 
 * first.
*/

final void writeChars(String s)
/*
 * Writes a string to the underlying output stream as a sequence of characters.
*/

final void writeDouble(double v)
/*
 * Converts the double argument to a long using the doubleToLongBits method in
 * class Double, and then writes that long value to the underlying output stream 
 * as an 8-byte quantity, high byte first.
*/

final void writeFloat(float v)
/*
 * Converts the float argument to an int using the floatToIntBits method in class
 * Float, and then writes that int value to the underlying output stream as a 
 * 4-byte quantity, high byte first.
*/

final void writeInt(int v)
/*
 * Writes an int to the underlying output stream as four bytes, high byte first.
*/

final void writeLong(long v)
/*
 * Writes a long to the underlying output stream as eight bytes, high byte first.
*/

final void writeShort(int v)
/*
 * Writes a short to the underlying output stream as two bytes, high byte first.
*/

final void writeUTF(String str)
/*
 * Writes a string to the underlying output stream using modified UTF-8 encoding
 * in a machine-independent manner.
*/
```

____
<br><br>

## DataInputStream

A data input stream lets an application read primitive java data types from an underlying input stream in a machine-independent way. An application uses a data output stream to write data that can later be read by a data input stream.

A `DataInputStream` is not safe for use by multiple concurrent threads if a `DataInputStream` is to be used by more than one thread then access to the data input stream should be controlled by appropriate synchronization.

```java
DataInputStream(InputStream in)
/*
 * Creates a DataInputStream that uses the specified underlying InputStream.
*/

final int read(byte[] b)
/*
 * Reads some number of bytes from the contained input stream and stores them
 * into the buffer array b.
*/

final int read(byte[] b, int off, int len)
/*
 * Reads up to len bytes of data from the contained input stream into an array of
 * bytes.
*/

// below function's description are same as the DataInput class methods. 

final boolean readBoolean()

final byte readByte()

final char readChar()

final double readDouble()

final float readFloat()

final void readFully(byte[] b)

final void readFully(byte[] b, int off, int len)

final int readInt()

final String readLine()

final long readLong()

final short readShort()

final int readUnsignedByte()

final int readUnsignedShort()

final String readUTF()

static final String readUTF(DataInput in)
/*
 * Reads from the stream in a representation of a Unicode character string
 * encoded in modified UTF-8 format; this string of characters is then returned
 * as a String.
*/

final int skipBytes(int n)
/*
 * skip n number of Bytes.
*/
```

____
<br><br>

## FilterInputStream

A `FilterInputStream` wraps some other input stream, which it uses as its basic source of data, possibly transforming the data along the way or providing additional functionality. The class `FilterInputStream` itself simply overrides select methods of InputStream with versions that pass all requests to the wrapped input stream. Subclasses of `FilterInputStream`, and may also provide additional fields and methods.

### FilterOutputStream's sub-classes

  1. BufferedInputStream
  2. CheckedInputStream
  3. CipherInputStream
  4. DataInputStream
  5. DeflaterInputStream
  6. DigestInputStream
  7. InflaterInputStream
  8. LineNumberInputStream
  9. ProgressMonitorInputStream
  10. PushbackInputStream

```java

int available()
/*
 * Returns an estimate of the number of bytes that can be read (or skipped over)
   from this input stream without blocking by the next caller of a method for
   this input stream.
 */

void close()
/*
 * Closes this input stream and releases any system resources associated with 
 * the stream.
*/

void mark(int readlimit)
/*
 * Marks the current position in this input stream.
*/

boolean markSupported()
/*
 * Tests if this input stream supports the mark and reset methods.
*/

int read()
/*
 * Reads the next byte of data from this input stream.
*/

int read(byte[] b)
/*
 * Reads up to b.length bytes of data from this input stream into an array of
 * bytes.
*/

int read(byte[] b, int off, int len)
/*
 * Reads up to len bytes of data from this input stream into an array of bytes.
*/

void reset()
/*
 * Repositions this stream to the position at the time the mark method was last
 * called on this input stream.
*/

long skip(long n)
/*
 * Skips over and discards n bytes of data from the input stream.
*/

```

____
<br><br>

## FilterOutputStream

This class is the superclass of all classes that filter output streams. These streams sit on top of an already existing output stream (the underlying output stream) which it uses as its basic sink of data, but possibly transforming the data along the way or providing additional functionality.

The class FilterOutputStream itself simply overrides all methods of OutputStream with versions that pass all requests to the underlying output stream. Subclasses of FilterOutputStream may further override some of these methods as well as provide additional methods and fields.

### FilterOutputStream's sub-classes

  1. BufferedOutputStream
  2. CheckedOutputStream
  3. CipherOutputStream
  4. DataOutputStream
  5. DeflaterOutputStream
  6. DigestOutputStream
  7. InflaterOutputStream
  8. PrintStream

```java

void close()
/*
 * Closes this output stream and releases any system resources associated with
 * the stream.
*/

void flush()
/*
 * Flushes this output stream and forces any buffered output bytes to be written
 * out to the stream.
*/

void write(byte[] b)
/*
 * Writes b.length bytes to this output stream.
*/

void write(byte[] b, int off, int len)
/*
 * Writes len bytes from the specified byte array starting at offset off to this output stream.
*/

void write(int b)
/*
 * Writes the specified byte to this output stream.
*/
```

## ObjectStreamClass

Serialization's descriptor for classes. It contains the name and serialVersionUID of the class. The ObjectStreamClass for a specific class loaded in this java VM can be found/created using the lookup method.

```java

Class<?> forClass()
/*
 * Return the class in the local VM that this version is mapped to.
*/

ObjectStreamField getField(String name)
/*
 * Get the field of this class by name.
*/

ObjectStreamField[] getFields()
/*
 * Return an array of the fields of this serializable class.
*/

String getName()
/*
 * Returns the name of the class described by this descriptor.
*/

long getSerialVersionUID()
/*
 * Return the serialVersionUID for this class.
*/

static ObjectStreamClass lookup(Class<?> cl)
/*
 * Find the descriptor for a class that can be serialized.
*/

static ObjectStreamClass lookupAny(Class<?> cl)
/*
 * Returns the descriptor for any class, regardless of whether it implements
   Serializable.
*/

String toString()
/*
 * Return a string describing this ObjectStreamClass.
*/
```

_____
<br><br>

## ObjectStreamField

A description of a Serializable field from a Serializable class. An array of ObjectStreamFields is used to declare the Serializable fields of a class.

```java

ObjectStreamField(String name, Class<?> type)
/*
 * Create a Serializable field with the specified type.
*/

ObjectStreamField(String name, Class<?> type, boolean unshared)
/*
 * Creates an ObjectStreamField representing a serializable field with the given
 * name and type.
*/

int compareTo(Object obj)
/*
 * Compare this field with another ObjectStreamField.
*/

String getName()
/*
 * Get the name of this field.
*/

int getOffset()
/*
 * Offset of field within instance data.
*/

Class<?> getType()
/*
 * Get the type of the field.
*/

char getTypeCode()
/*
 * Returns character encoding of field type.
*/

String getTypeString()
/*
 * Return the JVM type signature.
*/

boolean isPrimitive()
/*
 * Return true if this field has a primitive type.
*/

boolean isUnshared()
/*
 * Returns boolean value indicating whether or not the serializable field
 * represented by this ObjectStreamField instance is unshared.
*/

protected void setOffset(int offset)
/*
 * Offset within instance data.
*/

String toString()
/*
 * Return a string that describes this field.
*/
```

TypeCode returned by the getTypeCode()

```
B : byte
C : char
D : double
F : float
I : int
J : long
L : class or interface
S : short
Z : boolean
[ : array
```

_____
<br><br>

## Console

The Java Console class is be used to get input from console. It provides methods to read text and passwords.

Whether a virtual machine has a console is dependent, upon the underlying platform and also upon the manner in which the virtual machine is invoked. if the virtual machine is started from an interactive command line without redirecting the standard input and output streams then its console will exist and will typically be connected to the keyboard and display from which the virtual machine was launched. 

```java
Charset charset()
/*
 * Returns the Charset object used for the Console.
*/

void flush()
/*
 * Flushes the console and forces any buffered output to be written immediately.
*/

Console format(String fmt, Object... args)
/*
 * Writes a formatted string to this console's output stream using the specified
 * format string and arguments.
*/

Console printf(String format, Object... args)
/*
 * A convenience method to write a formatted string to this console's output
 * stream using the specified format string and arguments.
*/

Reader reader()
/*
 * Retrieves the unique Reader object associated with this console.
*/


String readLine()
/*
 * Reads a single line of text from the console.
*/


String readLine(String fmt, Object... args)
/*
 * Provides a formatted prompt, then reads a single line of text from the
 * console.
*/


char[] readPassword()
/*
 * Reads a password or passphrase from the console with echoing disabled
*/


char[] readPassword(String fmt, Object... args)
/*
 * Provides a formatted prompt, then reads a password or passphrase from the
 * console with echoing disabled.
*/

PrintWriter writer()
/*
 * Retrieves the unique PrintWriter object associated with this console.
*/
```
_____
<br><br>

## FilePermission

This class represent access to a file or directory. A FilePermission consists of a pathname and a set of action valid for that pathname.

* A Pathname is the pathname of the file or directory granted the specified actions. 
 
* A pathname that ends in "/*" (where "/" is the file separator character, File.separatorChar) indicated all the file and directories contained in that directory.

* A pathname that ends with "/-" indicated (recursively) all files and subdirectories contained in that directory. Such pathname is called a `wildcard`

* A pathname consisting of the special token `<<ALL FILES>>`  matches any file.


<div class='note'>
<p> <b>Note:</b> A pathname consisting of a single "*" indicates all the files in the current directory, while a pathname consisting of a single "-" indicates all the files in the current directory and (recursively) all files and subdirectories contained in the current directory.</p>
</div>

* **read**
  - read permission

* **write**
  - write permission

* **execute**
  - execute permission. Allow Runtime.exec to be called Corresponds to SecurityManager.checkExec.

* **delete**
  - delete permission. Allow File.delete to be called. Corresponds to SecurityManager.checkExec.

* **readlink**
  - read link permission. Allow the target of a symbolic link to be read by invoking the readSymbolicLink method.

* **write**
  - write permission


```java

FilePermission(String path, String actions)
/*
 * Creates a new FilePermission object with the specified actions.
*/

boolean equals(Object obj)
/*
 * Checks two FilePermission objects for equality.
*/

String getActions()
/*
 * Returns the "canonical string representation" of the actions.
*/

int hashCode()
/*
 * Returns the hash code value for this object.
*/

boolean implies(Permission p)
/*
 * Checks if this FilePermission object "implies" the specified permission.
*/

PermissionCollection newPermissionCollection()
/*
 * Returns a new PermissionCollection object for storing FilePermission objects.
*/

```

## Writer

Abstract class for writing to character streams. The only methods that a subclass must implement are write(char[], int, int), flush(), and close(). Most subclasses, however, will override some of the methods defined here in order to provide higher efficiency, additional functionality, or both.

### Writer's class sub-classes

* BufferedWriter
* CharArrayWriter
* FilterWriter
* OutputStreamWriter
* PipedWriter
* PrintWriter
* StringWriter

```java
protected Writer()
/*
 * Creates a new character stream writer whose critical sections will
 * synchronize on the writer itself.
*/

protected Writer(Object lock)
/*
 * Creates a new character-stream writer whose critical section will synchronize
 * on the given object.
*/

Writer append(char c)
/*
 * Appends the specified characters to this writer.
*/

Writer append(CharSequence csq)
/*
 * Appends the specified character sequence to this writer.
*/

Writer append(CharSequence csq, int start, int end)
/*
 * Appends a subsequence of the specified character sequence to this writer.
*/

abstract void close()
/*
 *  Closes the stream, flushing it first.
*/

abstract void flush()
/*
 *  Flushes the stream.
*/

static Writer nullWriter()
/*
 *  returns a new Writer which discards all characters.
*/

void writer(char[] cbuf)
/*
 *  Writes an array of characters.
*/

abstract void writer(char[] cbuf, int off, int len)
/*
 *  Writes a portion of an array of characters.
*/

void write(int c)
/*
 *  Writes a single characters.
*/

void write(String str)
/*
 *  Writes a string.
*/

void write(String str, int off, int len)
/*
 *  Writes a portion of a string.
*/
```

_____
<br><br>

## Reader

Abstract class for reading character streams. the only methods that a subclass must implement are read(char[], int, int) and close(). Most subclasses, however. will override some of the methods defined here in order to provide higher efficiency, additional functionality, or both.

### Reader's class sub-classes

* BufferedReader
* CharArrayReader
* FilterReader
* InputStreamReader
* PipedReader
* StringReader

```java
protected Reader()
/*
 * Creates a new character stream reader whose critical sections will
 * synchronize on the reader itself.
*/

protected Reader(Object lock)
/*
 * Creates a new character stream reader whose critical sections will
 * synchronize on the given object.
*/

abstract void close()
/*
 * Closes the stream and releases any system resources associated with it.
*/

void mark(int readAheadLimit)
/*
 * Marks the present position in the stream.
*/

boolean markSupported()
/*
 * Tells whether this stream supports the mark() operations.
*/

static Reader nullReader()
/*
 *  Returns anew Reader that reads no characters.
*/

int read()
/*
 *  Reads a single character.
*/

int read(char[] cbuf)
/*
 *  Reads characters into an array.
*/

abstract int read(char[] cbuf, int off, int len)
/*
 *  Reads characters into a portion of an array.
*/

int read(CharBuffer target)
/*
 *  Attempts to read characters into the specified character buffer.
*/

boolean read()
/*
 *  Tells whether this stream is ready to be read.
*/

void reset()
/*
 *  Resets the stream.
*/

long skip(long n)
/*
 *  Skips characters.
*/

long transferTo(Writer out)
/*
 *  Reads all characters from this reader and writes the characters to the given
 * writer in the order that they are read.
*/
```

_____
<br><br>

## FileWriter

Writes text to character files using a default buffer size. Encoding from charset to bytes uses either a specified charset or the default charset.

Whether or not a file is available or may be created depends upon the underlying platform. some platforms, in particular, allow a file to be opened for writing by only FileWriter (or other file-writing object) at a time. In this situations the constructor in this class will fail if the file involved is already upon.

Note: The `FileWriter` is meant for writing streams of characters. For writing streams of raw bytes, consider using a `FileOutputStream`.

```java
FileWriter(File file)
/*
  Constructs a FileWriter given the File to write, using the default charset.
*/

FileWriter(FileDescriptor fd)
/*
  Constructs a FileWriter given a file descriptor, using the default charset.
*/

FileWriter(File file, boolean append)
/*
  Constructs a FileWriter given the File to write and a boolean indicating
  whether to append the data written, using the default charset.
*/

FileWriter(File file, Charset charset)
/*
  Constructs a FileWriter given the File to write and a boolean indicating
  whether to append the data written, using the default charset.
*/

FileWriter(File file, Charset charset, boolean append)
/*
  Constructs a FileWriter given the File to write, charset and a boolean
  indicating whether to append the data written.
*/

FileWriter(String fileName)
/*
  Constructs a FileWriter given a file name, using the default charset.
*/

FileWriter(String fileName, boolean append)
/*
  Constructs a FileWriter given a file name and boolean indicating whether to
  append the data written, using the default charset.
*/

FileWriter(String fileName, Charset charset)
/*
  Constructs a FileWriter given a file name and charset.
*/

FileWriter(String fileName, Charset charset, boolean append)
/*
  Constructs a FileWriter given file name, charset and a boolean indicating
  whether to append the data written.
*/
```
_____
<br><br>

## FileReader

Reads text from character files using a default buffer size. Decoding form bytes to charset uses either a specified charset or the default charset.

Note: The `FileReader` is meant for reading streams of characters. For reading
streams of raw bytes, consider using a `FileInputStream`.

```java

FileReader(File file)
/*
  Creates a new FileReader, given the File to read, using the default charset.
*/

FileReader(FileDescriptor fd)
/*
  Creates a new FileReader, given the FileDescriptor to read using the default
  charset.
*/

FileReader(File file, Charset charset)
/*
  Creates a new FileReader, given the File to read and the charset.
*/

FileReader(String fileName)
/*
  Creates a new FileReader, Given the name of the file read, using the default charset.
*/

FileReader(String fileName, Charset charset)
/*
  Creates a new FileReader, given the name of the file to read and the charset.
*/
```

____
<br><br>

## BufferedWriter

Writes text to a character-output stream, buffering characters so as to provide for the efficient writing of single characters, arrays, and strings.

The buffer size may be specified, or the default size may be accepted. The default is large enough for most purposes.

A newLine() method is provided, which uses the platform's own notion of line separator as defined by the system property `line.separator`. Not all platforms use the newline character ('\n') to terminate lines. Calling this method to terminate each output line is therefore preferred to writing a newline character directly.

```java

BufferedWriter(Writer out)
/*
  Creates a buffered character-output stream that uses a default-sized output
  buffer.
*/

BufferedWriter(Writer out, int sz)
/*
  Creates a new buffered character-output stream that uses an output buffer of the given size.
*/

void close()
/*
  Closes the stream, flushing it first.
*/

void flush()
/*
  Flushes the stream.
*/

void newLine()
/*
  Writes a line separator.
*/

void write(char[] cbuf, int off, int len)
/*
  Writes a portion of an array of characters.
*/

void write(int c)
/*
  Writes a single character.
*/

void write(String s, int off, int len)
/*
  Writes a portion of a String.
*/
```
____
<br><br>

## BufferedReader

Reads text from a character-input stream, buffering characters so as to provide for the efficient reading of characters, arrays, and lines.

The buffer size may be specified, or the default size may be used. The default is large enough for most purposes.

```java

BufferedReader(Reader in)
/*
  Creates a buffering character-input stream that uses a default-sized input buffer.
*/

BufferedReader(Reader in, int sz)
/*
  Creates a buffering character-input stream that uses an input buffer of the specified size.
*/

void close()
/*
  Closes the stream and releases any system resources associated with it.
*/

Stream<String> lines()
/*
  Returns a Stream, the elements of which are lines read from this
  BufferedReader.
*/

void mark(int readAheadLimit)
/*
  Marks the present position in the stream.
*/

boolean markSupported()
/*
  Tells whether this stream supports the mark() operation, which it does.
*/

int read()
/*
  Reads a single character.
*/

int read(char[] cbuf, int off, int len)
/*
  Reads characters into a portion of an array.
*/

String readLine()
/*
  Reads a line of text.
*/

boolean ready()
/*
  Tells whether this stream is ready to be read.
*/

void reset()
/*
  Resets the stream to the most recent mark.
*/
```
____
<br><br>

## CharArrayReader

The `CharArrayReader` is composed of two words: CharArray and Reader. The 1 class is used to read character array as a reader (stream). It inherits `Reader` class.

```java

void close()
/*
  Closes the stream and releases any system resources associated with it.
*/

void mark(int readAheadLimit)
/*
 Marks the present position in the stream.
*/

boolean markSupported()
/*
 Tells whether this stream supports the mark() operation, which it does.
*/

int read()
/*
  Reads a single character.
*/

int read(char[] cbuf, int off, int len)
/*
  Reads characters into a portion of an array.
*/

boolean ready()
/*
  Tells whether this stream is ready to be read.
*/

void reset()
/*
  Resets the stream to the most recent mark, or to the beginning if it has
  never been marked.
*/

long skip(long n)
/*
  Skips characters.
*/
```

____ 
<br><br>

## CharArrayWriter

This class implements a character buffer that can be used as a Writer. The buffer automatically grows when data is written to the stream. The data can be retrieved using toCharArray() and toString().

Note: Note: Invoking close() on this class has no effect, and methods of this class can be called after the stream has closed without generating an IOException.

```java

CharArrayWriter append(char c)
/*
  Appends the specified character to this writer.
*/

CharArrayWriter append(CharSequence csq)
/*
  Appends the specified character sequence to this writer.
*/

CharArrayWriter append(CharSequence csq, int start, int end)
/*
  Appends a subsequence of the specified character sequence to this writer.
*/

void close()
/*
  Close the stream.
*/

void flush()
/*
  Flush the stream.
*/

void reset()
/*
  Resets the buffer so that you can use it again without throwing away the
  already allocated buffer.
*/

int size()
/*
  Returns the current size of the buffer.
*/

char[] toCharArray()
/*
  Returns a copy of the input data.
*/

String toString()
/*
  Converts input data to a string.
*/

void write(char[] c, int off, int len)
/*
  Writes characters to the buffer.
*/

void write(int c)
/*
  Writes a character to the buffer.
*/

void write(String str, int off, int len)
/*
  Write a portion of a string to the buffer.
*/

void writeTo(Writer out)
/*
  Write a portion of a string to the buffer.
*/

```
_____
<br><br>

## PrintStream

A PrintStream adds functionality to another output stream, namely the ability to print representations of various data values conveniently. Two other features are provided as well. 

Unlike other output streams, a PrintStream never throws an IOException; instead, exceptional situations merely set an internal flag that can be tested via the checkError method. Optionally, a PrintStream can be created so as to flush automatically; this means that the flush method of the underlying output stream is automatically invoked after a byte array is written, one of the println methods is invoked, or a newline character or byte ('\n') is written.

All characters printed by a PrintStream are converted into bytes using the given encoding or charset, or the default charset if not specified. The PrintWriter class should be used in situations that require writing characters rather than bytes.

This class always replaces malformed and unmappable character sequences with the charset's default replacement string. The CharsetEncoder class should be used when more control over the encoding process is required.

```java
PrintStream(File file)
/*
  Creates a new print stream, without automatic line flushing, with the 
  pecified file.
*/

PrintStream(File file, String csn)
/*
  Creates a new print stream, without automatic line flushing, with the
  specified file and charset.
*/

PrintStream(File file, Charset charset)
/*
  Creates a new print stream, without automatic line flushing, with the
  specified file and charset.
*/

PrintStream(OutputStream out)
/*
  Creates a new print stream, without automatic line flushing, with the
  specified OutputStream.
*/

PrintStream(OutputStream out, boolean autoFlush)
/*
  Creates a new print stream, with the specified OutputStream and line flushing.
*/

PrintStream(OutputStream out, boolean autoFlush, String encoding)
/*
  Creates a new print stream, with the specified OutputStream, line flushing,
  and character encoding.
*/

PrintStream(OutputStream out, boolean autoFlush, Charset charset)
/*
  Creates a new print stream, with the specified OutputStream, line flushing
  and charset.
*/

PrintStream(String fileName)
/*
  Creates a new print stream, without automatic line flushing, with the 
  specified file name.
*/

PrintStream(String fileName, String csn)
/*
  Creates a new print stream, without automatic line flushing, with the 
  specified file name and charset.
*/

PrintStream(String fileName, Charset charset)
/*
  Creates a new print stream, without automatic line flushing, with the
  specified file name and charset.
*/
```

**PrintStream Methods**
```java
PrintStream append(char c)
/*
  Appends the specified character to this output stream.
*/

PrintStream append(CharSequence csq)
/*
  Appends the specified character sequence to this output stream.
*/

PrintStream append(CharSequence csq, int start, int end)
/*
  Appends a subsequence of the specified character sequence to this output stream.
*/

Charset charset()
/*
  Returns the charset used in this PrintStream instance.
*/

boolean checkError()
/*
  Flushes the stream and checks its error state.
*/

protected void clearError()
/*
  Clears the internal error state of this stream.
*/

void close()
/*
  Closes the stream.
*/

void flush()
/*
  Flushes the stream.
*/

PrintStream format(String format, Object... args)
/*
  Writes a formatted string to this output stream using the specified format 
*/string and arguments.

PrintStream format(Locale l, String format, Object... args)
/*
  Writes a formatted string to this output stream using the specified format 
*/string and arguments.

void print(boolean b)
/*
  Prints a boolean value.
*/

void print(char c)
/*
  Prints a character.
*/

void print(char[] s)
/*
  Prints an array of characters.
*/

void print(double d)
/*
  Prints a double-precision floating-point number.
*/

void print(float f)
/*
  Prints a floating-point number.
*/

void print(int i)
/*
  Prints an integer.
*/

void print(long l)
/*
  Prints a long integer.
*/

void print(Object obj)
/*
  Prints an object.
*/

void print(String s)
/*
  Prints a string.
*/

PrintStream printf(String format, Object... args)
/*
  A convenience method to write a formatted string to this output stream using 
*/the specified format string and arguments.

PrintStream printf(Locale l, String format, Object... args)
/*
  A convenience method to write a formatted string to this output stream using 
*/the specified format string and arguments.

void println()
/*
  Terminates the current line by writing the line separator string.
*/

void println(boolean x)
/*
  Prints a boolean and then terminates the line.
*/

void println(char x)
/*
  Prints a character and then terminates the line.
*/

void println(char[] x)
/*
  Prints an array of characters and then terminates the line.
*/

void println(double x)
/*
  Prints a double and then terminates the line.
*/

void println(float x)
/*
  Prints a float and then terminates the line.
*/

void println(int x)
/*
  Prints an integer and then terminates the line.
*/

void println(long x)
/*
  Prints a long and then terminates the line.
*/

void println(Object x)
/*
  Prints an Object and then terminates the line.
*/

void println(String x)
/*
  Prints a String and then terminates the line.
*/

protected void setError()
/*
  Sets the error state of the stream to true.
*/

void write(byte[] buf)
/*
  Writes all bytes from the specified byte array to this stream.
*/

void write(byte[] buf, int off, int len)
/*
  Writes len bytes from the specified byte array starting at offset off to this 
*/stream.

void write(int b)
/*
  Writes the specified byte to this stream.
*/

void writeBytes(byte[] buf)
/*
  Writes all bytes from the specified byte array to this stream.
*/

```

_____
<br><br>

## PrintWriter

Prints formatted representations of objects to a text-output stream. This class implements all of the print methods found in PrintStream. It does not contain methods for writing raw bytes, for which a program should use unencoded byte streams.

Unlike the PrintStream class, if automatic flushing is enabled it will be done only when one of the println, printf, or format methods is invoked, rather than whenever a newline character happens to be output. These methods use the platform's own notion of line separator rather than the newline character.

**PrintWriter Constructor**
```java

PrintWriter(File file)
/*
  Creates a new PrintWriter, without automatic line flushing, with the specified file.

*/

PrintWriter(File file, String csn)
/*
  Creates a new PrintWriter, without automatic line flushing, with the specified file and charset.

*/

PrintWriter(File file, Charset charset)
/*
  Creates a new PrintWriter, without automatic line flushing, with the specified file and charset.

*/

PrintWriter(OutputStream out)
/*
  Creates a new PrintWriter, without automatic line flushing, from an existing OutputStream.

*/

PrintWriter(OutputStream out, boolean autoFlush)
/*
  Creates a new PrintWriter from an existing OutputStream.


*/
PrintWriter(OutputStream out, boolean autoFlush, Charset charset)
/*
  Creates a new PrintWriter from an existing OutputStream.


*/
PrintWriter(Writer out)
/*
  Creates a new PrintWriter, without automatic line flushing.


*/
PrintWriter(Writer out, boolean autoFlush)
/*
  Creates a new PrintWriter.


*/
PrintWriter(String fileName)
/*
  Creates a new PrintWriter, without automatic line flushing, with the specified file name.

*/

PrintWriter(String fileName, String csn)
/*
  Creates a new PrintWriter, without automatic line flushing, with the specified file name and charset.

*/

PrintWriter(String fileName, Charset charset)
/*
  Creates a new PrintWriter, without automatic line flushing, with the specified file name and charset.

*/
```

**PrintWriter Methods**

```java

PrintWriter append(char c)
/*
  Appends the specified character to this writer.
*/

PrintWriter append(CharSequence csq)
/*
  Appends the specified character sequence to this writer.
*/

PrintWriter append(CharSequence csq, int start, int end)
/*
  Appends a subsequence of the specified character sequence to this writer.
*/

boolean checkError()
/*
  Flushes the stream if it's not closed and checks its error state.
*/

protected void clearError()
/*
  Clears the error state of this stream.
*/

void close()
/*
  Closes the stream and releases any system resources associated with it.
*/

void flush()
/*
  Flushes the stream.
*/

PrintWriter format(String format, Object... args)
/*
  Writes a formatted string to this writer using the specified format string and arguments.
*/

PrintWriter format(Locale l, String format, Object... args)
/*
  Writes a formatted string to this writer using the specified format string and arguments. 
*/

void print(boolean b)
/*
  Prints a boolean value.
*/

void print(char c)
/*
  Prints a character.
*/

void print(char[] s)
/*
  Prints an array of characters.
*/

void print(double d)
/*
  Prints a double-precision floating-point number.
*/

void print(float f)
/*
  Prints a floating-point number.
*/

void print(int i)
/*
  Prints an integer.
*/

void print(long l)
/*
  Prints a long integer.
*/

void print(Object obj)
/*
  Prints an object.
*/

void print(String s)
/*
  Prints a string.
*/

PrintWriter printf(String format, Object... args)
/*
  A convenience method to write a formatted string to this writer using the 
  specified format string and arguments.  
*/

PrintWriter printf(Locale l, String format, Object... args)
/*
  A convenience method to write a formatted string to this writer using the 
  specified format string and arguments.  
*/

void println()
/*
  Terminates the current line by writing the line separator string.
*/

void println(boolean x)
/*
  Prints a boolean value and then terminates the line.
*/

void println(char x)
/*
  Prints a character and then terminates the line.
*/

void println(char[] x)
/*
  Prints an array of characters and then terminates the line.
*/

void println(double x)
/*
  Prints a double-precision floating-point number and then terminates the line.
*/

void println(float x)
/*
  Prints a floating-point number and then terminates the line.
*/

void println(int x)
/*
  Prints an integer and then terminates the line.
*/

void println(long x)
/*
  Prints a long integer and then terminates the line.
*/

void println(Object x)
/*
  Prints an Object and then terminates the line.
*/

void println(String x)
/*
  Prints a String and then terminates the line.
*/

protected void setError()
/*
  Indicates that an error has occurred.
*/

void write(char[] buf)
/*
  Writes an array of characters.
*/

void write(char[] buf, int off, int len)
/*
  Writes A Portion of an array of characters.
*/

void write(int c)
/*
  Writes a single character.
*/

void write(String s)
/*
  Writes a string.
*/

  void write(String s, int off, int len)
/*
  Writes a portion of a string.
*/

```
_____
<br><br>

## OutputStreamWriter

An OutputStreamWriter is a bridge from character streams to byte streams: Characters written to it are encoded into bytes using a specified charset. The charset that it uses may be specified by name or may be given explicitly, or the default charset may be accepted.

Each invocation of a write( method) cause the encoding converter to be invoked on the given character(s). The resulting bytes are accumulated in a buffer before being written to the underlying output stream. Note that the characters passed to the write() methods are not buffered.

**OutputStreamWriter Constructor**

```java
OutputStreamWriter(OutputStream out)
/*
  Creates an OutputStreamWriter that uses the default character encoding, or where out is a PrintStream, the charset used by the print stream.
*/

OutputStreamWriter(OutputStream out, String charsetName)
/*
  Creates an OutputStreamWriter that uses the named charset
*/

OutputStreamWriter(OutputStream out, Charset cs)
/*
  Creates an OutputStreamWriter that use the given charset.
*/

OutputStreamWriter(OutputStream out, CharsetEncoder enc)
/*
  Create an OutputStreamWriter that uses the given charset encoder.
*/
```

**OutputStreamWriter methods**

```java
void close()
/*
  Closes the stream, flushing it first.
*/

void flush()
/*
  Flushes the stream.
*/

String getEncoding()
/*
  Returns the name of the character encoding being used by this stream.
*/

void write(char[] cbuf, int off, int len)
/*
  Writes a portion of an array of characters.
*/

void write(int c)
/*
  Writes a single character.
*/

void write(String str, int off, int len)
/*
  Write a portion of a string.
*/
```
_____
<br><br>

## InputStreamReader

An InputStreamReader is a bridge from byte streams to character streams: it reads bytes and decodes them into characters using a specified charset. The charset that it is uses may be specified by name or may be given explicitly, or the default charset may be used.

Each invocation of one of an InputStreamReader's read() methods may cause one or more bytes to be read from the underlying byte-input stream. To enable the efficient conversion of bytes to charset, more bytes may be read ahead from the underlying stream than are necessary to satisfy the current read operation.

**InputStreamReader Constructor**

```java

InputStreamReader(InputStream in)
/*
  Creates an InputStreamReader that uses the default charset.
*/

InputStreamReader(InputStream in, String charsetName)
/*
  Creates an InputStreamReader that uses the named charset.
*/

InputStreamReader(InputStream in, Charset cs)
/*
  Creates an InputStreamReader that uses the given charset.
*/

InputStreamReader(InputStream in, CharsetDecoder dec)
/*
  Creates an InputStreamReader that uses the given charset decoder.
*/
```

**InputStreamReader Methods**

```java

void close()
/*
 Closes the stream and releases any system resources associated with it.
*/

String getEncoding()
/*
  Returns the name of the charset encoding being used by this stream.
*/

int read()
/*
  Reads a single character.
*/

int read(char[] cbuf, int off, int len)
/*
  Reads characters into a portion of an array.
*/

boolean ready()
/*
  Tells whether this stream is ready to be read.
*/
```
_____
<br><br>

## PushbackInputStream

A PushbackInputStream adds functionality to another input stream, namely the ability to "push back" or "unread" bytes, by storing pushed-back bytes in an internal buffer. This is useful in situations where it is convenient for a fragment of code to read indefinite number of data bytes that are delimited by a particular byte value; after reading the terminating byte, the code fragment can "unread" it, so that the next read operation on the input stream will reread the byte that was pushed back.

For example: bytes representing the characters constituting an identifier might be terminated by a byte representing an operator character; a method whose job is to read just an identifier can read until it sees the operator and then push the operator back to be re-read.

**PushbackInputStream Constructor**

```java
PushbackInputStream(InputStream in)
/*
  Creates a PushbackInputStream with a 1-byte pushback buffer, and saves its argument, the input stream in, far later use.
*/

PushbackInputStream(InputStream in, int size)
/*
Create a PushbackInputStream with a pushback buffer of the specified size, and saves its argument, the input stream in, for later us.
*/
```

**PushbackInputStream methods**

```java

int available()
/*
  Returns an estimate of the number of bytes that can be read (or skipped over) from this input stream without blocking by the next invocation of a method for this input stream.
*/

void close()
/*
  Closes this input stream and releases any system resources associated with the stream.
*/

void mark(int readlimit)
/*
  Marks the current position in this input stream.
*/

boolean markSupported()
/*
  Tests if this input stream supports the mark and reset methods, which it does not.
*/

int read()
/*
Reads the next byte of data from this input stream.
*/

int read(byte[] b, int off, int len)
/*
  Reads up to len bytes of data from this input stream into an array.
*/

void reset()
/*
  Reposition this stream to the position at the time the mark method was last called on this input stream.
*/

long skip(long n)
/*
  Skips over and discards n bytes of data from this input stream.
*/

void unread(byte[] b)
/*
  Pushes back an array of bytes by copying it to the front of the pushback buffer.
*/

void unread(byte[] b, int off, int len)
/*
  Pushes back a portion of an array of bytes by copying it to the front of the pushback buffer.
*/

void unread(int b)
/*
  Pushes back byte by copying it to the front of the pushback buffer.
*/
```
______
<br><br>

## PushbackReader

A character-stream reader that allows characters to be pushed back into the stream.

```java
PushbackReader(Reader in)
/*
  Creates a new pushback reader with one-character pushback buffer.
*/

PushbackReader(Reader in, int size)
/*
  Creates a new pushback reader with a pushback buffer of the given size.
*/
```

**PushbackInputStream methods**

```java
void close()
/*
  Closes the stream and release any system resources associated with it.
*/

void mark(int readAheadLimit)
/*
  Marks the present position in the stream.
*/

boolean markSuppoerted()
/*
  Tells whether this stream supports the mark() operation, which it does not.
*/

int read()
/*
  Reads a single character.
*/

boolean ready()
/*
  Tells whether this stream is ready to be read. 
*/

void unread(char[] cbuf)
/*
  Pushes back an array of characters by copying it to the font of the pushback buffer.
*/

void unread(char[] cbuf, int off, int len)
/*
  Pushes back a portion of an array of characters by copying it to the front of the pushback buffer.
*/

void unread(int c)
/*
  Pushes back a single character by copying it to the front of the pushback buffer.
*/
```
____
<br><br>

## StringReader

A character stream whose source is a string.

```java
StringReader(String s)
/*
  Creates a new string reader.
*/

void close()
/*
  Closes the stream and releases any system resources associated with it.
*/

void mark(int readAheadLimit)
/*
  Marks the present position in the stream.
*/

boolean markSupported()
/*
  Tells whether this stream supports the mark() operation, which it does.
*/

int read()
/*
  Reads a single character.
*/

int read(char[] cbuf, int off, int len)
/*
  Reads characters into a portion of an array.
*/

boolean ready()
/*
  Tells whether this stream is ready to be read.
*/

void reset()
/*
  Resets the stream to the most recent mark, or to the beginning of the string if it has never been marked.
*/

long skip(long n)
/*
  Skips characters.
*/
```