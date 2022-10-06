<style> 

    body{
        font-size: 1.2rem;
    }

    .note{
        max-width: 800px;
        padding: 10px;
        padding-left: 20px;
        background-color: rgba(0,133,242,.1);
        border-left: 5px solid #5e9eff;
        border-radius: 5px;
        margin: 10px;
    }
</style>

# JavaScript Event Introduction

Events are actions or occurrences that happen in the system in which we are programming. events are actions or occurrences that happen in the system we are programming, the system produces (or "fires") a signal of some kind when an event occurs, and provides a mechanism by which a action can be automatically taken when the event occurs.

For example, if the user clicks a button on a webpage, we might want to react to that action by displaying an information box.

in the case of the web, events are fired inside the browser window, and tends to be attached to a specific item that resides in it. this might be single element, a set of elements, the HTML document loaded in the current tab, or the entire browser window. There are many different types of events that can occur.

**For example:**

    * The user selects, clicks, or hovers the cursor over a certain element.
    * The user chooses a key on the keyboard.
    * The user resizes or closes the browser window.
    * a form is submitted.
    * A video is played, paused, or ends.
    * An error occurs.


To react to an event, we attach an event handler to it. This is a block of code (usually a function) that runs when the event fires. when such a block of code is defined to run in response to an event, we say we are registering an event handler.

`Note:` Event handlers are sometimes called **event listeners**, they are pretty much interchangeable for our purposes, they work together. The listener listens out for the event happening, and the handler is the code that is run in response to it happening.

<span style='color:red;'>Note:</span> Web events are not part of the core javaScript language, they defined as part of the APIs built into the browser.

### Example 1: Change color 

In this program we will make a div and a button, we will use the button to change the color of the div, all the code is defined in the below linked file.

[Example: change color](example1.html)

1. In this first we will create a button and a div.
2. give both of them unique id so we can access them.
3. generate random number in rgb pair to set the random color. (using `Math.random()` method)
4. add the event listener.


HTML Code
```html
    <button id="bt">Change Color</button>
    <div id="div1"></div>
```

JS code
```js

    const bt = document.getElementById("bt");
    const div = document.getElementById("div1")
    // Now we need to make a function which will give us the random

    function random(number) {
        return Math.floor(Math.random() * (number + 1));
        // Note here we are adding 1 into the number intentionally.
    }

    // Now we will make another function which will generate random
    // colors
    function random_color() {
        return `rgb(${random(255)}, ${random(255)}, ${random(255)})`
    }

    // Now we need to bind the onclick event to the button
    bt.addEventListener("click", () => {
        div.style.backgroundColor = random_color();
    })
```

### addEventListener()

The recommended mechanism fro adding event handlers in web pages is the` addEventListener()` method.

Note: In the ***Change Color*** example we have used the `addEventListener()` method to add an event listener for `click` event.

`addEventListener()` takes two parameters, **first:** the name of the event we want to register this handler for, **second:** the code that is the part of the handler function we want to run in response to it.

Note: we can use the separated named function as well as the anonymous function to run the code in response.

#### Other events 

There are many different events that can be fired by a button elements. Here we will see some of them.

* `focus` and `blur` -- These two events occurs whenever the button has gained the focus and becomes unfocused after gaining the focus. we can apply the some logic in the response of these event.

* `dblclick` -- This event occurs whenever double click is pressed on the button or any other element wherever this event is available.

* `mouseover` -- This event occurs whenever our mouse is on the button but button may or may not have the focus.

* `mouseout` -- This event occurs whenever our mouse is moved out from the button region.

Here in this example we can see the effect of this above mentioned events:[Other events Example]()

Note: Some events, such as **play**, are available only on the some element such as <video> or <audio> which contains playable data.


### Removing Listeners

if we have added an event handler using `addEventListener()`, we can remove it again using the removeEventListener() method.

```js
bt.removeEventListener("click", changeBackground)
```
Event handlers can also be removed by passing an `AbortSignal` to `addEventListener()` and then later calling abort() on the controller owing the `AbortSignal`.

For example:
```js
const controller = new AbortController();

btn.addEventListener('click', () => {
  const rndCol = `rgb(${random(255)}, ${random(255)}, ${random(255)})`;
  document.body.style.backgroundColor = rndCol;
}, { signal: controller.signal }); // pass an AbortSignal to this handler
```
Now, the event handler created by the code above can be removed like this:
```js
controller.abort();
// removing any or all event handlers associated with this controller.
```

<span style='color:#0077b6; font-weight:bold;'>Note:</span> For simple, small programs, cleaning up old, unused event handlers isn't necessary, but for larger, more complex programs, it can improve efficiency. Also, the ability to remove event handlers allows us to have the same button performing different action in the different circumstances: all we have to do is add or remove handlers 

**Adding multiple listeners for a single event**

we can add multiple listener for our single event by making more than one call to `addEventListener()`, providing different handlers.

```js
myElement.addEventListener('click', functionA);
myElement.addEventListener('click', functionB);
```

Both functions would now run when the element is clicked.

we have two more event listener mechanisms:

1. event handler properties
2. inline event handlers.

### Event handler properties

Objects (such as buttons) that can fire events also usually have properties whose name is on followed by the name of the event. For example, elements have a property onclick. This is called an event handler property. To listen for the event, you can assign the handler function to the property.

For example

```js
    const bt = document.getElementById("bt");
    const div = document.getElementById("div1")
    // Now we need to make a function which will give us the random

    function random(number) {
        return Math.floor(Math.random() * (number + 1));
        // Note here we are adding 1 into the number intentionally.
    }

    // Now we will make another function which will generate random
    // colors
    function random_color() {
        return `rgb(${random(255)}, ${random(255)}, ${random(255)})`
    }

    // Now we need to bind the click event to the button
    // by using the event handler property
    bt.onclick =  () => {
        div.style.backgroundColor = random_color();
    }
```

Note: With event handler properties, we can't add more than one andler for single event. 

if we want to add more event handler on an element than we can use the `AddEventListener()` method, with different functions specified.

```js
element.addEventListener('click', function1);
element.addEventListener('click', function2);
```

This is impossible with event handler properties because any subsequent attempts to set the property will overwrite earlier ones.

```js
element.onclick = function1;
element.onclick = function2;
```

### Inline event handlers

we can use the another kind of way to add the handlers for the event, which is inline handler. These handler are specified as the attribute value of the HTML element in the opening Tag. For example..

```js
<button onclick="bgChange()">Press me</button>
```
Here we are registering an event `click` prefixed with `on` with `bgChange` handler. The attribute value is literally the JavaScript code we want to run when the event occurs. Here we can add the javascript directly inside the attribute. For example

```js
<button onclick="alert('Hello, this is my old-fashioned event handler!');">
  Press me
</button>
```

You can find HTML attribute equivalents for many of the event handler properties; however, you shouldn't use these — they are considered bad practice. It might seem easy to use an event handler attribute if you are doing something really quick, but they quickly become unmanageable and inefficient.

<span style='color:red;'>Warning:</span> many common server configuration will disallow inline JavaScript, as a security measure. we should never use the HTML event handler attributes, those are outdated, and using them is bad practice.

____
____

## Event Object

Whenever a event handler function is registered to an event, then this event on fire pass an argument which can be refereed as `event`, `ev`, or `e`. This is called `event object`, and it is automatically passed to event handlers to provide extra features and information.

For example:

```js

    const bt = document.getElementById("bt");
    const div = document.getElementById("div1")
    // Now we need to make a function which will give us the random

    function random(number) {
        return Math.floor(Math.random() * (number + 1));
        // Note here we are adding 1 into the number intentionally.
    }

    // Now we will make another function which will generate random
    // colors
    function random_color() {
        return `rgb(${random(255)}, ${random(255)}, ${random(255)})`
    }

    // Now we need to bind the onclick event to the button
    bt.addEventListener("click", (e) => {
        div.style.backgroundColor = random_color();
        console.log(e);
    })
```
To live result please check this [event Object ](example2.html);

Here we have added event object e, in the function and in the function. event object has a property named as `target`. The `target` property of the event object is always a reference to the element to the element the event occurred upon.

### Extra Properties of event objects

Most event objects have a standard set of properties and methods available on the event object.

Some event objects add extra properties that are relevant to that particular type of event. For example, the `keydown` event fires when the user presses a key. its event obj3ect is a `keyboardEvent`, which is specialized Event. object with `key` property that tells us which key is pressed.

HTML
```html
    <input id="textBox" type="text" /><br>
    <div id="output"></div>
```
JS Code
```js
    const textBox = document.getElementById("textBox");
    const output = document.getElementById("output");

    // now we need to add the event listener 
    textBox.addEventListener('keypress', (event) => {
        output.textContent = `Pressed key: "${event.key}"`
    })
```

To live result please check this [Keyboard Event Object ](example3.html);

## Preventing default behavior

Sometimes, you'll come across a situation where you want to prevent an event from doing what it does by default. The most common example is that of a web form, for example, a custom registration form. When you fill in the details and click the submit button, the natural behavior is for the data to be submitted to a specified page on the server for processing, and the browser to be redirected to a "success message" page of some kind (or the same page, if another is not specified).

These default behavior creates a problem when the user submit the incorrect data on the server, then we have to stop the submission and show the error message that the submission is wrong. This kind of mechanism can be applied with the proper form validation functions.

we can check this example: [formValidation Example](formValidationTest.html)


## Event bubbling and capture

Event bubbling and capture are terms that describe phases in how the browser handles events targeted at nested elements.

**Setting a listener on a parent element**

Consider a small html web page like below mentioned!...

```html
<div id="container">
  <button>Click me!</button>
</div>
<pre id="output"></pre>
```

Here the button is inside another element, a `<div>` element. we sayy that the `<div>` element here is the parent of the element it contains.

<span style='color:#BB6B24; font-weight:bold;'>Note:</span> what happens if we add a click event handler to the parent, then click the button?

```js
const output = document.getElementById('output');
function handleClick(e) {

    // we are setting the textContent on the output.
    // here we have used the currentTarget property and tagName
    // of the currentTarget,
  output.textContent += `You clicked on a ${e.currentTarget.tagName} element\n`;
}

const container = document.getElementById('container');
container.addEventListener('click', handleClick);
```

Note: here if we press the button then we will get the message "`You clicked on a DIV element`", it means parent fires a click event when the user clicks the buttons, here the button is inside the `<div>` , so when we click the button we are also implicitly clicking the element it is inside.

### Example of bubbling

In this example we will add event listener to the button, div as well as the body to see the effect of the event bubbling. for that we will use the below HTML code.

```html
<body>
  <div id="container">
    <button id="bt">Click me!</button>
  </div>
  <output id="output"></output>
</body>
```

Now we will add the event listener to button, div and the body.

```js
// first we will get the div and button element
const bt = document.getElementById("bt");
const container = document.getElementById("container");
// we also need to output
const output = document.getElementById("output");
// now we need to make a common function in response.
function handleClick(e) {
    output.textContent += `You have clicked on a ${e.currentTarget.tagName} element\n`;
    console.log(`You have clicked on a ${e.currentTarget.tagName} element`)
}
// Now we will register this function with the body, container and
// button click event.
document.body.onclick = handleClick;
container.onclick = handleClick;
bt.onclick = handleClick;
```
From the above example we will see that all three elements fire a click event when the user clicks the button.

```
You clicked on a BUTTON element
You clicked on a DIV element
You clicked on a BODY element
```

In this case:

 1. The click on the button fires first.
 2. followed by the click on its parent (the div element)
 3. followed by the `<div>` element's parent (the body element)

we describe this by saying that the event `bubbles up` from the innermost element that was clicked.

Note: In many cases this kind of behavior can be useful and can also cause unexpected problems.

### Bubbling Example 

```html
<div id="outerContainer">

        <div id="innerContainer" style="display: none;">
            <h1>Hello, How are you</h1>
        </div>

    </div>

    <!-- Here we also have a button. -->
    <button id="bt">show</button>
```

Now we will make the js code for this html to show the event bubbling.
```js
const outer = document.getElementById("outerContainer");
const inner = document.getElementById("innerContainer");
const bt = document.getElementById("bt");

// Registering the event handler for the button
bt.onclick = (e) => {
    inner.style.display = "flex";
}

// Registering the event handler for the outer div
outer.onclick = (e) => {
    inner.style.display = "none";
}
```

In this case:

1. Whenever we click on the button innerContainer should will be visible.
2. Whenever we click on the outer button innerContainer should be invisible.
3. But after visible, when we click on the on the innerContainer it becomes invisible.
4. This kind of behavior of event bubbling create problem in this kind of situation where we don't want do fire other event when we don't need them.

**Bubbling and capturing**

when an event is fired on an element that ahs parent elements, modern browsers run three different phases, the capturing phase, the target phase, and the bubbling phase.

* **In the capturing phase:**
  
  * The browser checks to see if the element's outer-most ancestor (`<html>`) has a click event handler registered on it for the capturing phase, and runs it if so.
  
  * Then it moves on to the next element inside `<html>` and does the same thing, then the next one, and so on until it reaches the direct parent of the element that was actually clicked.


* **In the target phase:**
  
  * The browser checks to see if the target property has an event handler for the click event registered on it, and runs it if so.
  
  * Then, if `bubbles` is true, it propagates the event to the direct parent of the clicked element, then the next one, and so on until it reaches the `<html>` element. Otherwise, if `bubbles` is `false`, it doesn't propagate the event to any ancestors of the target.


* **In the bubbling phase, the exact opposite of the capturing phase occurs:**
  * The browser checks to see if the direct parent of the clicked element has a click event handler registered on it for the bubbling phase, and runs it if so.
  
  * Then it moves on to the next immediate ancestor element and does the same thing, then the next one, and so on until it reaches the `<html>` element.

Note: in modern browsers, by default, all event handlers are registered for the bubbling phase.


<div class='note'>
<p> <b>Note:</b> All JavaScript events fo through the capturing and target phases. Whether an event enters the bubbling phases can be checked by the read-only `bubbles` property</p>
</div>


<div class='note'>
<p> <b>Note:</b> Event Listener registered for the &lt;html&gt; element arent't at the top of the hierarchy. For example, event listeners registered for the <b>window</b> and <b>document</b> objects are higher in the hierarchy.</p>  
</div>

### Fixing the problem with stopPropagation()

As we know that bubbling of events can create a huge problem in many situation, but there is a way to prevent it. The standard `Event` object has a method available on it called `stopPropagation()` which,, when invoked on a handler's event object, makes it so that hte first handler is run but the event doesn't bubble any further up the chain, so no more handlers will be run. 

Now in our `eventBubblingTest` example we will add the another event handler for the `innerContainer` which will prevent the bubbling.

```js
inner.onclick = (e) => {
    e.stopPropagation();
    // this will stop the event bubbling
}
```
<div class='note'>
<p> <b>Note:</b> As mentioned above, by default almost all event handlers are registered in the bubbling phase, and this make more senses most of the time. if we really want to register an event in the capturing phase instead, we can do so by registering our handler using <b>addEventListener()</b>, and setting the optional third property to true.</p>
</div>


## Event delegation

Event bubbling isn't just annoying though; it can be very useful. in particular, it enables a practice called event delegation. In this practice, when we want some code to run when the user interacts with any one of a large number of child elements, we set the event listener on their parent and have events that happen on them bubble up to their parent rather than having to set the event listener on every child individually.

