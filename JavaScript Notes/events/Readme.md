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

[Example: change color](events/example1.html)

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
To live result please check this [event Object ](events/example2.html) 
