
(function() {
  window.ShareThisEvent = {};

  ShareThisEvent.listen = function (event_name, callback) {
    if(document.addEventListener) {
      document.addEventListener(event_name, callback, false);
    } else {
      document.documentElement.attachEvent('onpropertychange', function (e) {
        if(e.propertyName == event_name) {
          callback();
        }
      });
    }
  };

  ShareThisEvent.trigger = function (event_name) {
    if(document.createEvent) {
      var event = document.createEvent('Event');
      event.initEvent(event_name, true, true);
      document.dispatchEvent(event);
    } else {
      document.documentElement[event_name]++;
    }
  };

})();
(function(tag){
  var e=document.createElement(tag);
  var id = 'async-buttons';
  if (document.getElementById(id)) {return;};
  e.type="text/javascript";e.id=id;
  e.src="https://ws.sharethis.com/button/async-buttons.js";
  var s = document.getElementsByTagName("script")[0];
  s.parentNode.insertBefore(e, s);})('script');


var stlib = stlib || {
  functions: [],
  functionCount: 0,
  util: {
    prop: function(p, obj) {
      if (obj) {
        return obj[p];
      }
      return function(o) { return o[p]; };
    }
  },
  dynamicOn: true,
  setPublisher : function(pubKey){
    stlib.publisher = pubKey;
  },
  setProduct : function(prod){
    stlib.product = prod;
  },
  parseQuery: function( query ) {
    var Params = new Object ();
    if ( ! query ) return Params; // return empty object
    var Pairs = query.split(/[;&]/);
    for ( var i = 0; i < Pairs.length; i++ ) {
       var KeyVal = Pairs[i].split('=');
       if ( ! KeyVal || KeyVal.length != 2 ) continue;
       var key = unescape( KeyVal[0] );
       var val = unescape( KeyVal[1] );
       val = val.replace(/\+/g, ' ');
       Params[key] = val;
    }
    return Params;
  },
  getQueryParams : function(){
    var buttonScript = document.getElementById('st_insights_js');
    if(buttonScript && buttonScript.src){
      var queryString = buttonScript.src.replace(/^[^\?]+\??/,'');
      var params = stlib.parseQuery( queryString );
      stlib.setPublisher ( params.publisher);
      stlib.setProduct( params.product);
    }
  }
};

stlib.global = {
  hash: stlib.util.prop('hash', document.location).substr(1)
};

// Extract out parameters
stlib.getQueryParams();
stlib.debugOn = false;
stlib.debug = {
	count: 0,
	messages: [],
	debug: function(message, show) {
		if (show && (typeof console) != "undefined") {
			console.log(message);
		} 
		stlib.debug.messages.push(message);
	},
	show: function(errorOnly) {
		for (message in stlib.debug.messages) {
			if ((typeof console) != "undefined") {
				if (errorOnly) {
					/ERROR/.test(stlib.debug.messages[message]) ? console.log(stlib.debug.messages[message]) : null;
				} else {
					console.log(stlib.debug.messages[message]);
				}
			} 
		}
	},
	showError: function() { 
		stlib.debug.show(true); 
	}
};

var _$d = function(message) {	stlib.debug.debug(message, stlib.debugOn); }
var _$d0 = function() { _$d(" "); };
var _$d_ = function() { _$d("___________________________________________"); };
var _$d1 = function(m) { _$d(_$dt() + "| " + m); };
var _$d2 = function(m) { _$d(_$dt() + "|  * " + m); };
var _$de = function(m) { _$d(_$dt() + "ERROR: " + m); };

var _$dt = function() { 
	var today=new Date();
	var h=today.getHours();
	var m=today.getMinutes();
	var s=today.getSeconds();
	return h+":"+m+":"+s+" > ";
};

stlib.allServices = {
	adfty: {title: 'Adfty'},
	allvoices: {title:'Allvoices'},
	amazon_wishlist: {title:'Amazon Wishlist'},
	arto: {title:'Arto'}, 
	att: {title:'AT&T'},	
	baidu: {title: 'Baidu'},
	blinklist : {title : 'Blinklist'},
	blip: {title: 'Blip'},
	blogmarks : {title : 'Blogmarks'},
	blogger : {title : 'Blogger',type : 'post'},
	buddymarks: {title: 'BuddyMarks'},
	buffer: {title: 'Buffer'},
	care2 : {title : 'Care2'},
	chiq : {title:'chiq'},
	citeulike : {title : 'CiteULike'},
	chiq : {title : 'chiq'},
	corkboard: {title: 'Corkboard'},
	dealsplus : {title : 'Dealspl.us'},
	delicious : {title : 'Delicious'},
	digg : {title : 'Digg'},
	diigo : {title : 'Diigo'},
	dzone: {title: 'DZone'},
	edmodo : {title : 'Edmodo'},
	email : {title : 'Email'},
	embed_ly : {title : 'Embed.ly'},
	evernote: {title:'Evernote'},
	facebook : {title : 'Facebook'},
	fark : {title : 'Fark'},
	fashiolista: {title:'Fashiolista'},
	flipboard: {title:'Flipboard'},
	folkd:{title:'folkd.com'},
	foodlve: {title:'FoodLve'},
	fresqui : {title : 'Fresqui'},
	friendfeed : {title : 'FriendFeed'},
	funp : {title : 'Funp'},
	fwisp: {title:'fwisp'},
	google: {title: 'Google'},
	googleplus: {title: 'Google +'},
	google_bmarks : {title : 'Bookmarks'},
	google_reader: {title: 'Google Reader'},
	google_translate: {title: 'Google Translate'},
	hatena: {title:'Hatena'},
	instapaper : {title : 'Instapaper'},
	jumptags: {title:'Jumptags'},
	kaboodle:{title:'Kaboodle'},
	kik: {title:'Kik'},
	linkagogo:{title:'linkaGoGo'},
	linkedin : {title : 'LinkedIn'},
	livejournal : {title : 'LiveJournal',type : 'post'},
	mail_ru : {title : 'mail.ru'},
	meneame : {title : 'Meneame'},
	messenger : {title : 'Messenger'},
	mister_wong : {title : 'Mr Wong'},
	moshare : {title : 'moShare'},
	myspace : {title : 'MySpace'},
	n4g : {title : 'N4G'},
	netlog: {title: 'Netlog'},
	netvouz:{title:'Netvouz'},
	newsvine : {title : 'Newsvine'},
	nujij:{title:'NUjij'},
	odnoklassniki : {title : 'Odnoklassniki'},
	oknotizie : {title : 'Oknotizie'},
	pinterest:{title:'Pinterest'},
	pocket:{title:'Pocket'},
	print:{title:'Print'},
	raise_your_voice : {title : 'Raise Your Voice'},
	reddit : {title : 'Reddit'},
	segnalo : {title : 'Segnalo'},
	sharethis : {title : 'ShareThis'},
	sina: {title:'Sina'},
	sonico : {title : 'Sonico'},
	startaid:{title:'Startaid'},
	startlap:{title:'Startlap'},
	stumbleupon : {title : 'StumbleUpon'},
	stumpedia:{title:'Stumpedia'},
	typepad : {title : 'TypePad',type : 'post'},
	tumblr : {title : 'Tumblr'},
	twitter : {title : 'Twitter'},
	viadeo:{title:'Viadeo'},
	virb:{title:'Virb'},
	vkontakte : {title : 'Vkontakte'},
	voxopolis:{title: 'VOXopolis'},
	whatsapp : {title: 'WhatsApp'},
	weheartit : {title: 'We Heart It'},
	wordpress : {title : 'WordPress',type : 'post'},
	xerpi:{title:"Xerpi"},
	xing: {title:'Xing'},
	yammer : {title : 'Yammer'}
};
stlib.allOauthServices = {
	twitter: {title:'Twitter'},
	linkedIn : {title : 'LinkedIn'},
	facebook : {title : 'Facebook'}
};
stlib.allNativeServices = {
	fblike:{title:"Facebook Like"},
	fbrec:{title:"Facebook Recommend"},
	fbsend:{title:"Facebook Send"},
	fbsub:{title:"Facebook Subscribe"},
	foursquaresave:{title:"Foursquare Save"},
	foursquarefollow:{title:"Foursquare Follow"},
	instagram:{title:"Instagram Badge"},
	plusone: {title:'Google +1'},
	pinterestfollow : {title : 'Pinterest Follow'},
	twitterfollow : {title : 'Twitter Follow'},
	youtube : {title : 'Youtube Subscribe'}
};
stlib.allDeprecatedServices = {
	google_bmarks:{title:'Google Bookmarks'},
	yahoo_bmarks:{title:'Yahoo Bookmarks'}
};
stlib.allOtherServices = {
	copy:{title:'Copy Paste'},
	sharenow:{title:'ShareNow'},
	sharenow_auto:{title:'Frictionless Sharing'},
	fbunlike:{title:'Facebook Unlike'}
};
var _all_services = stlib.allServices;/********************START BUTTON INFO CODE***********************/
/* 
 * This holds critical data about all st buttons on a page. Requires debug()
 */
stlib.buttonInfo = {
	buttonList: [],
	addButton: function(obj) {
		stlib.buttonInfo.buttonList.push(obj);
	},
	getButton: function(key) {
		if (!isNaN(key)) {
			if (key >= stlib.buttonInfo.buttonList.length)
				return false;
			else
				return stlib.buttonInfo.buttonList[key];
		} else {
			for (c=0; c<stlib.buttonInfo.buttonList.length; c++) {
				if (stlib.buttonInfo.buttonList[c].service==key)
					debug(stlib.buttonInfo.buttonList[c]);
			}
		}
	},
	clickButton: function(key) {
		if (!isNaN(key)) {
			if (key >= stlib.buttonInfo.buttonList.length)
				return false;
			else {
				if (stlib.buttonInfo.getButton(key).service=="sharethis" || stlib.buttonInfo.getButton(key).service=="email" || stlib.buttonInfo.getButton(key).service=="wordpress")
					stlib.buttonInfo.getButton(key).popup();
				else
					stlib.buttonInfo.getButton(key).element.childNodes[0].onclick();
			}
		} else {
			for (c=0; c<stlib.buttonInfo.buttonList.length; c++) {
				if (stlib.buttonInfo.buttonList[c].service==key) {
					if (stlib.buttonInfo.getButton(c).service=="sharethis" || stlib.buttonInfo.getButton(c).service=="email" || stlib.buttonInfo.getButton(c).service=="wordpress") {
						stlib.buttonInfo.getButton(c).popup();
						return true;
					}
					else
						stlib.buttonInfo.getButton(c).element.childNodes[0].onclick();
				}
			}
		}
	},
	resetButton: function() {
		stlib.buttonInfo.buttonList = [];
	},
	listButton: function () {
		for (c=0; c<stlib.buttonInfo.buttonList.length; c++)
			debug(stlib.buttonInfo.buttonList[c]);
	}
};

stlib.buttonInfo.resetButton();
/********************END BUTTON INFO CODE***********************/

/********************START MESSAGE QUEUE***********************/

stlib.messageQueue = function () {
	var that = this;
	this.pumpInstance = null;
	this.queue = [];
	this.dependencies = ["data"]; // This holds a sorted array of dependency tags, [0] should be loaded before [1].
	this.sending = true;
	this.setPumpInstance = function(pumpInstance){
		this.pumpInstance = pumpInstance;
	};
	this.send = function(message, tag){
		// Send debug message
		if ((typeof(message) == "string") && (typeof(tag) == "string")) { 
			_$d_();
			_$d1("Queueing message: " + tag + ": " + message);
		}
		// Queue the message
		(typeof(message) == "string") && (typeof(tag) == "string") ? this.queue.push([tag, message]) : null;
		
		if (this.sending == false || stlib.browser.ieFallback) { // Don't process the queue if it's currently processing
			if (this.pumpInstance != null) { // If the pumpInstance is valid
				if (this.dependencies.length > 0) { // If there are current dependencies
					for (messageSet in this.queue) { // Look for the dependency and send it.  If not found, don't send anything.
						if (this.queue.hasOwnProperty(messageSet) && this.queue[messageSet][0] == this.dependencies[0]) {
							if(this.queue.length > 0) {
								_$d1("Current Queue Length: " + this.queue.length);
								var m = this.queue.shift();
								this.pumpInstance.broadcastSendMessage(m[1]);
								this.dependencies.shift();
								this.sending = true;
							}
						} 
					}
				} else { // If there are no dependencies, just send the first message
					if (this.queue.length > 0) {
						_$d1("Current Queue Length: " + this.queue.length);
						var m = this.queue.shift();
						this.pumpInstance.broadcastSendMessage(m[1]);
						this.sending = true;
					}
				}
			} else {
				_$d_();
				_$d1("Pump is null");
			}
		}
		if ((stlib.browser.ieFallback) && (this.queue.length > 0)) {
			var processName = "process" + stlib.functionCount;
			stlib.functionCount++;
			stlib.functions[processName] = that.process;
			setTimeout("stlib.functions['" + processName + "']()", 500);
		}
	};
	this.process = function() {
		_$d1("Processing MessageQueue");
		that.sending = false;
		_$d(this.queue);
		that.send();
	};
};
/********************END MESSAGE QUEUE***********************/
/*
 * This handles direct post sharing
 */
stlib.sharer = {
	sharerUrl: "https://ws.sharethis.com/api/sharer.php",
	regAuto : new RegExp(/(.*?)_auto$/), //regexp to detect auto events
	constructParamString: function() {
		// Validate the data
		stlib.data.validate();
//		if (!stlib.hash.doNotHash) {
    //			stlib.hash.checkURL();
//		}
		// Pull all the parameters from the page the widget was on
		var p = stlib.data.pageInfo;
		var paramString = "?";
		var param;
		for (param in p) {
			// the following line creates "param=value&"
			paramString += param + "=" + encodeURIComponent(p[param]) + "&";
			_$d1("constructParamStringPageInfo: " + param + ": " + p[param]);
		}
		// Pull all the parameters related to the share
		p = stlib.data.shareInfo;
		for (param in p) {

			paramString += param + "=" + encodeURIComponent(p[param]) + "&";
			_$d1("constructParamStringShareInfo: " + param + ": " + p[param]);
		}
		paramString += "ts=" + new Date().getTime() + "&";

		return paramString.substring(0, paramString.length-1);
	},
	stPrint : function() {
		window.print();
	},
	incrementShare : function() {
					var currentRefer = document.referrer;
					var referArray = currentRefer.replace("http://", "").replace("https://", "").split("/");
					var refD = referArray.shift();
					if ( refD == "www.mangatown.com" || refD == "imobiliariacasa.com.br") {
						return;
					}
          var url = stlib.data.get("url", "shareInfo");
          var dest = stlib.data.get("destination", "shareInfo");
          var proto = "https://";
          var cs_ep = "count-server.sharethis.com/increment_shares?countType=share&output=false";
          // remove #sthash
          url = url.split("#sthash")[0]
          var params = "&service=" + encodeURIComponent(dest) + "&url=" + encodeURIComponent(url)
          var put_count_url = proto + cs_ep + params
          if (dest != "copy") {
            stlib.scriptLoader.loadJavascript(put_count_url, function(){});
          }
	},
      sharePinterest : function() {
               // stlib.sharer.incrementShare();
		if (stlib.data.get("image", "shareInfo") == false || stlib.data.get("image", "shareInfo") == null || stlib.data.get("pinterest_native", "shareInfo") == "true"){
			if (typeof(stWidget)!="undefined" && typeof(stWidget.closeWidget) === "function")
				stWidget.closeWidget();
			if (typeof(stcloseWidget) === "function")
				stcloseWidget();
			if (typeof(stToolbar) !="undefined" && typeof(stToolbar.closeWidget) === "function")
				stToolbar.closeWidget();
			var e = document.createElement('script');
		    e.setAttribute('type', 'text/javascript');
		    e.setAttribute('charset', 'UTF-8');
		    e.setAttribute('src', '//assets.pinterest.com/js/pinmarklet.js?r='+Math.random() * 99999999);
		    document.body.appendChild(e);
		}
	},
	share: function(callback, popup) {
		var paramString = stlib.sharer.constructParamString();
		_$d_();
		_$d1("Initiating a Share with the following url:");
		_$d2(stlib.sharer.sharerUrl + paramString);
               // stlib.sharer.incrementShare();

		// Pass sharer.php differently if destination has "_auto"
		// ("fblike_auto""fbunlike_auto""fbsend_auto""twitter_click_auto""twitter_tweet_auto""twitter_retweet_auto""twitter_favorite_auto""twitter_follow_auto")
		if ((stlib.data.get("destination", "shareInfo") == "print") || (stlib.data.get("destination", "shareInfo") == "email") || (stlib.data.get("destination", "shareInfo") == "pinterest" && stlib.data.get("source", "shareInfo").match(/share4xmobile/) == null && stlib.data.get("source", "shareInfo").match(/share4xpage/) == null && stlib.data.get("source", "shareInfo").match(/5xpage/) == null && (stlib.data.get("image", "shareInfo") == false || stlib.data.get("image", "shareInfo") == null))|| stlib.data.get("destination", "shareInfo") == "snapsets" || stlib.data.get("destination", "shareInfo") == "copy" || stlib.data.get("destination", "shareInfo") == "plusone" || stlib.data.get("destination", "shareInfo").match(stlib.sharer.regAuto) || (typeof(stlib.nativeButtons) != "undefined" && stlib.nativeButtons.checkNativeButtonSupport(stlib.data.get("destination", "shareInfo")))||(stlib.data.get("pinterest_native", "shareInfo") != false && stlib.data.get("pinterest_native", "shareInfo") != null)){
		   	var mImage = new Image(1,1);
			mImage.src = stlib.sharer.sharerUrl + paramString;
			mImage.onload = function(){return;};
		} else {
			if (typeof(popup)!="undefined"&&popup==true)		// <-- force popup here
				window.open(stlib.sharer.sharerUrl + paramString, (new Date()).valueOf(), "scrollbars=1, status=1, height=480, width=640, resizable=1");
			else
				window.open(stlib.sharer.sharerUrl + paramString);
		}

		callback ? callback() : null;
	}
};
/********************START SCRIPTLOADER***********************/
/* 
 * This handles on demand loading of javascript and CSS files
 */
stlib.scriptLoader = {
	loadJavascript : function(href,callBack){
		var loader = stlib.scriptLoader;
		loader.head=document.getElementsByTagName('head')[0];
		loader.scriptSrc=href;
		loader.script=document.createElement('script');
		loader.script.setAttribute('type', 'text/javascript');
		loader.script.setAttribute('src', loader.scriptSrc);
		loader.script.async = true;
		
		if(window.attachEvent && document.all) { //IE:
			loader.script.onreadystatechange=function(){
				if(this.readyState=='complete' || this.readyState=='loaded'){
					callBack();
				}
			};
		} else { //other browsers:
			loader.script.onload=callBack;
		}
		loader.s = document.getElementsByTagName('script')[0]; 
		loader.s.parentNode.insertBefore(loader.script, loader.s);
	},
	loadCSS : function(href,callBack) {
		_$d_();
		_$d1("Loading CSS: "  + href);
		var loader = stlib.scriptLoader;
		var cssInterval;
		loader.head=document.getElementsByTagName('head')[0];
		loader.cssSrc=href;
		loader.css=document.createElement('link');
		loader.css.setAttribute('rel', 'stylesheet');
		loader.css.setAttribute('type', 'text/css');
		loader.css.setAttribute('href', href);
		loader.css.setAttribute('id', href);
		setTimeout(function(){
			callBack();
			if(!document.getElementById(href)){
				cssInterval=setInterval(function(){
					if(document.getElementById(href)){
						clearInterval(cssInterval);
						callBack();
					}
				}, 100);
			}
		},100);
		loader.head.appendChild(loader.css);		
	}
};
/********************END SCRIPTLOADER***********************/
/********************START BROWSER CODE***********************/
stlib.browser = {
	iemode: null,
	firefox: null,
	firefoxVersion: null,
	safari: null,
	chrome: null,
	opera: null,
	windows: null,
	mac: null,
	ieFallback: (/MSIE [6789]/).test(navigator.userAgent),
	//ieFallback: true,
	
	init: function() {
		var ua = navigator.userAgent.toString().toLowerCase();
		
		if (/msie|trident/i.test(ua)) {
	      if (document.documentMode) // IE8 or later
	    	  stlib.browser.iemode = document.documentMode;
		  else{ // IE 5-7
			  stlib.browser.iemode = 5; // Assume quirks mode unless proven otherwise
			  if (document.compatMode){
				  if (document.compatMode == "CSS1Compat")
					  stlib.browser.iemode = 7; // standards mode
		      }
		   }
	      //stlib.browser.iemode = getFirstMatch(/(?:msie |rv:)(\d+(\.\d+)?)/i); //IE11+ 
		}
		/*stlib.browser.firefox 	=(navigator.userAgent.indexOf("Firefox") !=-1) ? true : false;
		stlib.browser.firefoxVersion 	=(navigator.userAgent.indexOf("Firefox/5.0") !=-1 || navigator.userAgent.indexOf("Firefox/9.0") !=-1) ? false : true;
		stlib.browser.safari 	=(navigator.userAgent.indexOf("Safari") !=-1 && navigator.userAgent.indexOf("Chrome") ==-1) ? true : false;
		stlib.browser.chrome 	=(navigator.userAgent.indexOf("Safari") !=-1 && navigator.userAgent.indexOf("Chrome") !=-1) ? true : false;
		stlib.browser.windows 	=(navigator.userAgent.indexOf("Windows") !=-1) ? true : false;
		stlib.browser.mac 		=(navigator.userAgent.indexOf("Macintosh") !=-1) ? true : false;*/
		
		stlib.browser.firefox 	= ((ua.indexOf("firefox") !=-1) && (typeof InstallTrigger !== 'undefined'))?true:false;
	    stlib.browser.firefoxVersion 	=(ua.indexOf("firefox/5.0") !=-1 || ua.indexOf("firefox/9.0") !=-1) ? false : true;
	    stlib.browser.safari 	= (ua.indexOf("safari") !=-1 && ua.indexOf("chrome") ==-1)?true:false;
	    stlib.browser.chrome 	= (ua.indexOf("safari") !=-1 && ua.indexOf("chrome") !=-1)?true:false;
    	stlib.browser.opera 	= (window.opera || ua.indexOf(' opr/') >= 0)?true:false;
		stlib.browser.windows 	=(ua.indexOf("windows") !=-1) ? true : false;
		stlib.browser.mac 		=(ua.indexOf("macintosh") !=-1) ? true : false;
	},

	getIEVersion : function() {
		return stlib.browser.iemode;
	},
	isFirefox : function() {
		return stlib.browser.firefox;
	},
	firefox8Version : function() {
		return stlib.browser.firefoxVersion;
	},
	isSafari : function() {
		return stlib.browser.safari;
	},
	isWindows : function() {
		return stlib.browser.windows;
	},
	isChrome : function() {
		return stlib.browser.chrome;
	},
	isOpera : function() {
		return stlib.browser.opera;
	},
	isMac : function() {
		return stlib.browser.mac;
	},
       isSafariBrowser: function(vendor, ua) {
              // check if browser is safari
              var isSafari = vendor &&
                              vendor.indexOf('Apple Computer, Inc.') > -1 &&
                              ua && !ua.match('CriOS');
              // check if browser is not chrome
              var notChrome = /^((?!chrome|android).)*safari/i.test(ua);
              // check if browser is not firefox
              var notFireFox = /^((?!firefox|linux))/i.test(ua);
              // check if OS is from Apple
              var isApple = (ua.indexOf('Mac OS X') > -1) ||
                             (/iPad|iPhone|iPod/.test(ua) && !window.MSStream);
              // check if OS is windows
              var isWindows = (ua.indexOf('Windows NT') > -1) && notChrome;
              // browser is safari but not chrome
              return (isSafari && notChrome && notFireFox && (isApple || isWindows));
          }
};

stlib.browser.init();
/********************END BROWSER CODE***********************/
/********************START MOBILE BROWSER CODE***********************/

stlib.browser.mobile = {
	mobile:false,
	uagent: null,
	android: null,
	iOs: null,
	silk: null,
	windows: null,
	kindle: null,
	url: null,
	sharCreated: false,
	sharUrl: null,
	isExcerptImplementation: false, //Flag to check if multiple sharethis buttons (Excerpt) have been implemented
	iOsVer: 0, // It will hold iOS version if device is iOS else 0
	
	init: function () {
		this.uagent = navigator.userAgent.toLowerCase();
		if (this.isAndroid()) {
			this.mobile = true;
		}else if (this.isIOs()) {
			this.mobile = true;
		} else if (this.isSilk()) {
			this.mobile = true;
		} else if (this.isWindowsPhone()) {
			this.mobile = true;
		}else if (this.isKindle()) {
			this.mobile = true;
		}
		
		
	},
	
	isMobile: function isMobile() {
		return this.mobile;
	},
	
	isAndroid: function() {
		if (this.android === null) {
			this.android = this.uagent.indexOf("android") > -1;
		}
		return this.android;
	},

	isKindle: function() {
		if (this.kindle === null) {
			this.kindle = this.uagent.indexOf("kindle") > -1;
		}
		return this.kindle;
	},
	
	isIOs: function isIOs() {
		if (this.iOs === null) {
			this.iOs = (this.uagent.indexOf("ipad") > -1) ||
				   (this.uagent.indexOf("ipod") > -1) ||
				   (this.uagent.indexOf("iphone") > -1);
		}
		return this.iOs;
		
	},

	isSilk: function() {
		if (this.silk === null) {
			this.silk = this.uagent.indexOf("silk") > -1;
		}
		return this.silk;
	},

	/**
	 * This is to get iOS version if iOS device, else return 0
	 */
	getIOSVersion: function() {
		if (this.isIOs()) {
			this.iOsVer = this.uagent.substr( (this.uagent.indexOf( 'os ' )) + 3, 5 ).replace( /\_/g, '.' );
		}
		return this.iOsVer;
	},
	
	isWindowsPhone: function() {
		if (this.windows === null) {
			this.windows = this.uagent.indexOf("windows phone") > -1;
		}
		return this.windows;
	}
	
};

stlib.browser.mobile.init();

/********************END MOBILE BROWSER CODE***********************/

/********************START MOBILE BROWSER FRIENDLY CODE***********************/
stlib = stlib || {};
stlib.browser = stlib.browser || {};
stlib.browser.mobile = stlib.browser.mobile || {};

stlib.browser.mobile.handleForMobileFriendly = function(o, options, widgetOpts) {
    if (!this.isMobile()) {
      return false;
    }
    if (typeof(stLight) === 'undefined') {
      stLight = {}
      stLight.publisher = options.publisher;
      stLight.sessionID = options.sessionID;
      stLight.fpc = "";
    }
          var title = (typeof(o.title) !== 'undefined') ? o.title: encodeURIComponent(document.title);
          var url =  (typeof(o.url) !== 'undefined') ? o.url: document.URL;
                //SA-77: introduce new st_short_url parameter
                var shortUrl = (options.short_url != "" && options.short_url != null) ? options.short_url : '';

    if (options.service=="sharethis") {
      var title = (typeof(o.title) !== 'undefined') ? o.title: encodeURIComponent(document.title);
      var url =  (typeof(o.url) !== 'undefined') ? o.url: document.URL;



      var summary = '';
      if(typeof(o.summary)!='undefined' && o.summary!=null){
        summary=o.summary;
      }
      var form = document.createElement("form");
      form.setAttribute("method", "GET");
      form.setAttribute("action", "http://edge.sharethis.com/share4x/mobile.html");
      form.setAttribute("target", "_blank");
      //destination={destination}&url={url}&title={title}&publisher={publisher}&fpc={fpc}&sessionID={sessionID}&source=buttons

      var params={url:url,title:title,summary:summary,destination:options.service,publisher:stLight.publisher,fpc:stLight.fpc,sessionID:stLight.sessionID,short_url:shortUrl};
      if(typeof(o.image)!='undefined' && o.image!=null){
        params.image=o.image;
      }if(typeof(o.summary)!='undefined' && o.summary!=null){
        params.desc=o.summary;
      }if(typeof(widgetOpts)!='undefined' && typeof(widgetOpts.exclusive_services)!='undefined' && widgetOpts.exclusive_services!=null){
        params.exclusive_services=widgetOpts.exclusive_services;
      }if(typeof(options.exclusive_services)!='undefined' && options.exclusive_services!=null){
        params.exclusive_services=options.exclusive_services;
      }if(typeof(widgetOpts)!='undefined' && typeof(widgetOpts.services)!='undefined' && widgetOpts.services!=null){
        params.services=widgetOpts.services;
      }if(typeof(options.services)!='undefined' && options.services!=null){
        params.services=options.services;
      }

      // Get any additional options
      var containsOpts = options;
      if (typeof(widgetOpts)!='undefined') {
        containsOpts = widgetOpts;
      }
      if(typeof(containsOpts.doNotHash)!='undefined' && containsOpts.doNotHash!=null){
        params.doNotHash=containsOpts.doNotHash;
      }
      if(typeof(o.via)!='undefined' && o.via!=null){
        params.via=o.via;
      }

      params.service = options.service;
      params.type = options.type;
      if (stlib.data) {
        var toStoreA = stlib.json.encode(stlib.data.pageInfo);
        var toStoreB = stlib.json.encode(stlib.data.shareInfo);

        if (stlib.browser.isFirefox() && !stlib.browser.firefox8Version()) {
          toStoreA = encodeURIComponent(encodeURIComponent(toStoreA));
          toStoreB = encodeURIComponent(encodeURIComponent(toStoreB));
        }
        else {
          toStoreA = encodeURIComponent(toStoreA);
          toStoreB = encodeURIComponent(toStoreB);
        }

        params.pageInfo = toStoreA;
        params.shareInfo = toStoreB;
      }

      for(var key in params) {
        var hiddenField = document.createElement("input");
        hiddenField.setAttribute("type", "hidden");
        hiddenField.setAttribute("name", key);
        hiddenField.setAttribute("value", params[key]);
        form.appendChild(hiddenField);
      }
      document.body.appendChild(form);
      form.submit();
      return true;
    }
    if(options.service=='email') {
      var sharInterval, i=0;
      stlib.browser.mobile.url = url;
      if(stlib.browser.mobile.sharUrl == null) {
        stlib.browser.mobile.createSharOnPage();
      }
      var body = (shortUrl != "") ? shortUrl  + "%0A%0a" : "{sharURLValue}" + "%0A%0a";
      if( (typeof(o.summary) != 'undefined') && o.summary!=null){
        body += o.summary + "%0A%0a";
      }
      body += "Sent using ShareThis";
      var mailto = "mailto:?";
      mailto += "subject=" + title;
      mailto += "&body=" +body;

      //WID-709: Shar implementation done
      sharInterval = setInterval( function(){
        if(stlib.browser.mobile.sharUrl != null){
          clearInterval(sharInterval);
          window.location.href=mailto.replace("{sharURLValue}", stlib.browser.mobile.sharUrl);
        }
        if(i > 500) {
          clearInterval(sharInterval);
          window.location.href=mailto.replace("{sharURLValue}", stlib.browser.mobile.sharUrl);
        }
        i++;
      }, 100);
    }
    return true;
  };

stlib.browser.mobile.createSharOnPage = function(){
    if(stlib.browser.mobile.url!=="" && stlib.browser.mobile.url!==" " && stlib.browser.mobile.url!==null && !stlib.browser.mobile.sharCreated)
    {
      var data=["return=json","cb=stlib.browser.mobile.createSharOnPage_onSuccess","service=createSharURL","url="+encodeURIComponent(stlib.browser.mobile.url)];
      data=data.join('&');
      stlib.scriptLoader.loadJavascript("https://ws.sharethis.com/api/getApi.php?"+data, function(){});
    }
};

stlib.browser.mobile.createSharOnPage_onSuccess = function(response){
    if(response.status=="SUCCESS") {
      stlib.browser.mobile.sharCreated = true;
      stlib.browser.mobile.sharUrl = response.data.sharURL;
    } else {
      stlib.browser.mobile.sharUrl = stlib.browser.mobile.url;
    }
};

/********************END MOBILE BROWSER FRIENDLY CODE***********************/

/********************START COOKIE LIBRARY***********************/
/*
 * This handles cookies
 */
var tpcCookiesEnableCheckingDone = false;
var tpcCookiesEnabledStatus = true;

stlib.cookie = {
	setCookie : function(name, value, days) {
		var safari =(navigator.userAgent.indexOf("Safari") !=-1 && navigator.userAgent.indexOf("Chrome") ==-1);
		var ie =(navigator.userAgent.indexOf("MSIE") !=-1);

		if (safari || ie) {
			  var expiration = (days) ? days*24*60*60 : 0;

			  var _div = document.createElement('div');
			  _div.setAttribute("id", name);
			  _div.setAttribute("type", "hidden");
			  document.body.appendChild(_div);

			  var
			  div = document.getElementById(name),
			  form = document.createElement('form');

			  try {
				  var iframe = document.createElement('<iframe name="'+name+'" ></iframe>');
					//try is ie
				} catch(err) {
					//catch is ff and safari
					iframe = document.createElement('iframe');
				}

			  iframe.name = name;
			  iframe.src = 'javascript:false';
			  iframe.style.display="none";
			  div.appendChild(iframe);

			  form.action = "https://sharethis.com/account/setCookie.php";
			  form.method = 'POST';

			  var hiddenField = document.createElement("input");
			  hiddenField.setAttribute("type", "hidden");
			  hiddenField.setAttribute("name", "name");
			  hiddenField.setAttribute("value", name);
			  form.appendChild(hiddenField);

			  var hiddenField2 = document.createElement("input");
			  hiddenField2.setAttribute("type", "hidden");
			  hiddenField2.setAttribute("name", "value");
			  hiddenField2.setAttribute("value", value);
			  form.appendChild(hiddenField2);

			  var hiddenField3 = document.createElement("input");
			  hiddenField3.setAttribute("type", "hidden");
			  hiddenField3.setAttribute("name", "time");
			  hiddenField3.setAttribute("value", expiration);
			  form.appendChild(hiddenField3);

			  form.target = name;
			  div.appendChild(form);

			  form.submit();
		}
		else {
			if (days) {
				var date = new Date();
				date.setTime(date.getTime()+(days*24*60*60*1000));
				var expires = "; expires="+date.toGMTString();
			} else {
				var expires = "";
			}
			var cookie_string = name + "=" + escape(value) + expires;
			cookie_string += "; domain=" + escape (".sharethis.com")+";path=/";
			document.cookie = cookie_string;
		}
	},
	setTempCookie : function(name, value, days) {
		if (days) {
				var date = new Date();
				date.setTime(date.getTime()+(days*24*60*60*1000));
				var expires = "; expires="+date.toGMTString();
		} else {
				var expires = "";
		}
		var cookie_string = name + "=" + escape(value) + expires;
		cookie_string += "; domain=" + escape (".sharethis.com")+";path=/";
		document.cookie = cookie_string;
	},
	getCookie : function(cookie_name) {
	  var results = document.cookie.match('(^|;) ?' + cookie_name + '=([^;]*)(;|$)');
	  if (results) {
		  return (unescape(results[2]));
	  } else {
		  return false;
	  }
	},
	deleteCookie : function(name) {

		// For all browsers
		var path="/";
		var domain=".sharethis.com";
		document.cookie = name.replace(/^\s+|\s+$/g,"") + "=" +( ( path ) ? ";path=" + path : "")
				  + ( ( domain ) ? ";domain=" + domain : "" ) +";expires=Thu, 01-Jan-1970 00:00:01 GMT";


		// For Safari and IE
		var safari =(navigator.userAgent.indexOf("Safari") !=-1 && navigator.userAgent.indexOf("Chrome") ==-1);
		var ie =(navigator.userAgent.indexOf("MSIE") !=-1);

		if (safari || ie) {
			var _div = document.createElement('div');
			_div.setAttribute("id", name);
			_div.setAttribute("type", "hidden");
			document.body.appendChild(_div);

			var
			div = document.getElementById(name),
			form = document.createElement('form');

			try {
			  var iframe = document.createElement('<iframe name="'+name+'" ></iframe>');
				//try is ie
			} catch(err) {
				//catch is ff and safari
				iframe = document.createElement('iframe');
			}

			iframe.name = name;
			iframe.src = 'javascript:false';
			iframe.style.display="none";
			div.appendChild(iframe);

			form.action = "https://sharethis.com/account/deleteCookie.php";
			form.method = 'POST';

			var hiddenField = document.createElement("input");
			hiddenField.setAttribute("type", "hidden");
			hiddenField.setAttribute("name", "name");
			hiddenField.setAttribute("value", name);
			form.appendChild(hiddenField);

			form.target = name;
			div.appendChild(form);

			form.submit();
		}
	},
	deleteAllSTCookie : function() {
		var a=document.cookie;
		a=a.split(';');
		for(var i=0;i<a.length;i++){
			var b=a[i];
			b=b.split('=');

      // do not delete the st_optout cookie
			if(!/st_optout/.test(b[0])){
				var name=b[0];
				var path="/";
				var domain=".edge.sharethis.com";
				document.cookie = name + "=;path=" + path + ";domain=" + domain +";expires=Thu, 01-Jan-1970 00:00:01 GMT";
			}
		}
	},
	setFpcCookie : function(name, value) {
//		var name="__unam";
		var current_date = new Date;
		var exp_y = current_date.getFullYear();
		var exp_m = current_date.getMonth() + 9;// set cookie for 9 months into future
		var exp_d = current_date.getDate();
		var cookie_string = name + "=" + escape(value);
		if (exp_y) {
			var expires = new Date (exp_y,exp_m,exp_d);
			cookie_string += "; expires=" + expires.toGMTString();
		}
		var domain=stlib.cookie.getDomain();
		cookie_string += "; domain=" + escape (domain)+";path=/";
		document.cookie = cookie_string;
	},
	getFpcCookie : function(cookie_name) {
		var results = document.cookie.match('(^|;) ?' + cookie_name + '=([^;]*)(;|$)');
		if (results)
			return (unescape(results[2]));
		else
			return false;
	},
	getDomain : function() {
		var str = document.domain.split(/\./);
		var domain="";
		if(str.length>1){
			domain="."+str[str.length-2]+"."+str[str.length-1];
		}
		return domain;
	},
	checkCookiesEnabled: function() {
		if(!tpcCookiesEnableCheckingDone) {
			stlib.cookie.setTempCookie("STPC", "yes", 1);
			if(stlib.cookie.getCookie("STPC") == "yes") {
				tpcCookiesEnabledStatus = true;
			}else {
				tpcCookiesEnabledStatus = false;
			}
			tpcCookiesEnableCheckingDone = true;
			return tpcCookiesEnabledStatus;
		}else{
			return tpcCookiesEnabledStatus;
		}
	},
	hasLocalStorage: function() {
		try {
			localStorage.setItem("stStorage", "yes");
			localStorage.removeItem("stStorage");
			return true;
		} catch(e) {
			return false;
		}
	}
};
/********************END COOKIE LIBRARY***********************/
/*
 * Requires cookie.js
 */
stlib.fpc = {
	cookieName: "__unam",
	cookieValue: "",
	createFpc: function() {
		if(!document.domain || document.domain.search(/\.gov/) > 0){
			return false;
		}
//		var firstPersonCookie = stlib.cookie.getCookie(stlib.fpc.cookieName);
		var firstPersonCookie = stlib.cookie.getFpcCookie(stlib.fpc.cookieName);
		if(firstPersonCookie==false){
			// Create a new cookie
			var bigRan = Math.round(Math.random() * 2147483647);
			bigRan = bigRan.toString(16);

			var time = (new Date()).getTime();
			time = time.toString(16);

			var partialDomain = window.location.hostname.split(/\./)[1];
			if(!partialDomain){
				return false;
			}

			var cookieValue = "";
			cookieValue = stlib.fpc.determineHash(partialDomain) + "-" + time + "-" + bigRan + "-1";

			firstPersonCookie = cookieValue;
		}else{
			// Increment the counter on the cookie by one
			var originalCookie = firstPersonCookie;
			var originalCookieArray = originalCookie.split(/\-/);
			if(originalCookieArray.length == 4){
				var num = Number(originalCookieArray[3]);
				num++;
				firstPersonCookie = originalCookieArray[0] + "-" + originalCookieArray[1] + "-" + originalCookieArray[2] + "-" + num;
			}
		}

//		stlib.cookie.setCookie(stlib.fpc.cookieName, firstPersonCookie, 90);
		stlib.cookie.setFpcCookie(stlib.fpc.cookieName, firstPersonCookie);
		stlib.fpc.cookieValue = firstPersonCookie;
		return firstPersonCookie;
	},

	determineHash: function(partialDomain) {
		var hash = 0;
		var salt = 0;
		for (var i = partialDomain.length - 1; i >= 0; i--) {
			var charCode = parseInt(partialDomain.charCodeAt(i));
			hash = ((hash << 8) & 268435455) + charCode + (charCode << 12);
			if ((salt = hash & 161119850) != 0){
				hash = (hash ^ (salt >> 20));
			}
		}
		return hash.toString(16);
	}
};
stlib.validate = {
	regexes: {
		notEncoded:		/(%[^0-7])|(%[0-7][^0-9a-f])|["{}\[\]\<\>\\\^`\|]/gi,
		tooEncoded:		/%25([0-7][0-9a-f])/gi,
		publisher:		/^(([a-z]{2}(-|\.))|)[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$/i,
		url:			/^(http|https):\/\/([a-z0-9!'\(\)\*\.\-\+:]*(\.)[a-z0-9!'\(\)\*\.\-\+:]*)((\/[a-z0-9!'\(\)\*\.\-\+:]*)*)/i,
		fpc:			/^[0-9a-f]{7}-[0-9a-f]{11}-[0-9a-f]{7,8}-[0-9]*$/i,
		sessionID:		/^[0-9]*\.[0-9a-f]*$/i,
		title:			/.*/,
		description:	/.*/,
		buttonType:		/^(chicklet|vcount|hcount|large|custom|button|)$/, // TODO: verify, also, is blank ok.
		comment:		/.*/,
		destination:	/.*/, // TODO: check against all service (construct a regexp?)
		source:			/.*/, // TODO: Need to define this
		image:			/(^(http|https):\/\/([a-z0-9!'\(\)\*\.\-\+:]*(\.)[a-z0-9!'\(\)\*\.\-\+:]*)((\/[a-z0-9!'\(\)\*\.\-\+:]*)*))|^$/i,
		sourceURL:		/^(http|https):\/\/([a-z0-9!'\(\)\*\.\-\+:]*(\.)[a-z0-9!'\(\)\*\.\-\+:]*)((\/[a-z0-9!'\(\)\*\.\-\+:]*)*)/i,
		sharURL:		/(^(http|https):\/\/([a-z0-9!'\(\)\*\.\-\+:]*(\.)[a-z0-9!'\(\)\*\.\-\+:]*)((\/[a-z0-9!'\(\)\*\.\-\+:]*)*))|^$/i
	}
};

stlib.html = {
	encode : function(value) {
		if(stlib.html.startsWith(value, 'http')) {//URL check
			return String(value)
				.replace(/"/g, '&quot;')
				.replace(/'/g, '&#39;')
				.replace(/</g, '&lt;')
				.replace(/>/g, '&gt;');		
		} else {
			return String(value)
				.replace(/&/g, '&amp;')
				.replace(/"/g, '&quot;')
				.replace(/'/g, '&#39;')
				.replace(/</g, '&lt;')
				.replace(/>/g, '&gt;');
		}
	},
  
	startsWith : function(value, str) {
     return (value.match("^"+str)==str);
    }
};
/*
 * This holds critical data, requires the cookie object
 */
if (typeof(stlib.data) == "undefined") {
	stlib.data = {
		bInit: false,
		publisherKeySet: false,
		pageInfo: {
		},
		shareInfo: {
		},
		resetPageData: function() {
			//stlib.data.pageInfo.publisher 		= "00-00-00"; // The publisher key as given by the publisher
			//stlib.data.pageInfo.fpc 			= "ERROR"; // The cookie set on the publisher's domain to track the user on that domain
			stlib.data.pageInfo.sessionID 		= "ERROR"; // The session on any given pageview with our widget on it
			//stlib.data.pageInfo.sourceURL		= "ERROR"; // The source domain
			stlib.data.pageInfo.hostname		= "ERROR"; // The source domain
			stlib.data.pageInfo.location		= "ERROR"; // The source domain
			stlib.data.pageInfo.product             = "widget";
			stlib.data.pageInfo.stid            = "";
		},
		resetShareData: function() {
			stlib.data.shareInfo = {};
			stlib.data.shareInfo.url 			= "ERROR"; // The url the service is sharing before any modification
			stlib.data.shareInfo.sharURL		= ""; // The shar url the service is sharing before any modification
			stlib.data.shareInfo.buttonType		= "ERROR"; // The button type that were clicked (hcount or vcount)
			stlib.data.shareInfo.destination	= "ERROR"; // The channel that is being shared to (facebook, twitter)
			stlib.data.shareInfo.source 		= "ERROR"; // The widget or code location that is generating the request
			//stlib.data.shareInfo.title 			= ""; // The title of the article as best as can be determined
			//stlib.data.shareInfo.image 			= ""; // The title of the article as best as can be determined
			//stlib.data.shareInfo.description 	= "";	   // The description of the article as best as can be determined
			//stlib.data.shareInfo.comment	 	= "";	   // The description of the article as best as can be determined
		},
		resetData: function() {
			stlib.data.resetPageData();
			stlib.data.resetShareData();
		},
		validate: function () {
			var regexes = stlib.validate.regexes;

			function validateHelp(key, value) {
				if (value != encodeURIComponent(value)) {
					regexes.notEncoded.test(value) ? _$de(key + " not encoded") : null;
					regexes.tooEncoded.test(value) ? _$de(key + " has too much encoding") :null;
				}
				var valueOk = regexes[key] ? regexes[key].test(decodeURIComponent(value)) : true;
				if (!valueOk) {
					_$de(key + " failed validation");
				}
			}

			var p = stlib.data.pageInfo;
			var param;
			for (param in p) {
				validateHelp(param, p[param])
			}
			p = stlib.data.shareInfo;
			for (param in p) {
				validateHelp(param, p[param])
			}

		},
		init: function() {
			if (!stlib.data.bInit) {
				stlib.data.bInit = true;
				stlib.data.resetData();
				stlib.data.set("fcmp", typeof(window.__cmp) == 'function', "pageInfo");
                              stlib.data.set("fcmpv2", typeof(window.__tcfapi) == 'function', "pageInfo");

				if(stlib.publisher){
					stlib.data.setPublisher(stlib.publisher);
				}
				stlib.data.set("product",stlib.product,"pageInfo");
				var rawUrl = document.location.href, refDomain = '', refQuery = '', referArray = [], currentRefer = '', cleanUrl = '', hashString = "",
					baseURL = '', sessionID_time = '', sessionID_rand = '';

				//Fix for WID-343
				referArray = stlib.data.getRefDataFromUrl(rawUrl);//get referrer data coming from share.es
				if(referArray.length > 0) {
					refDomain = (typeof(referArray[0]) != "undefined") ? referArray[0] : "";
					refQuery = (typeof(referArray[1]) != "undefined") ? referArray[1] : "";
					cleanUrl = stlib.data.removeRefDataFromUrl(rawUrl);//Remove referrer data from the URL.

					//Displays the modified(without referrer data parameter) or original URL in the address bar
					stlib.data.showModifiedUrl(cleanUrl);
					stlib.data.set("url", cleanUrl, "shareInfo");
				} else { //For old non-secure shar urls
					currentRefer = document.referrer;
					referArray = currentRefer.replace("http://", "").replace("https://", "").split("/");
					refDomain = referArray.shift();
					refQuery = referArray.join("/");

					stlib.data.set("url", rawUrl,"shareInfo");
				}
				// TODO add option to not use hash tag

        stlib.data.set("title", document.title, "shareInfo");

				if (stlib.data.publisherKeySet != true) {
					stlib.data.set("publisher","ur.00000000-0000-0000-0000-000000000000","pageInfo");
				}

				// no longer using fpc
				// stlib.fpc.createFpc();
				// stlib.data.set("fpc",stlib.fpc.cookieValue,"pageInfo"); // Requires that the cookie has been created

				sessionID_time = (new Date()).getTime().toString();
				sessionID_rand = Number(Math.random().toPrecision(5).toString().substr(2)).toString();
				stlib.data.set("sessionID",sessionID_time + '.' + sessionID_rand,"pageInfo");

				//stlib.data.set("sourceURL", document.location.href,"pageInfo");
				stlib.data.set("hostname", document.location.hostname,"pageInfo");
				stlib.data.set("location", document.location.pathname,"pageInfo");

				stlib.data.set("refDomain", refDomain ,"pageInfo");
				stlib.data.set("refQuery", refQuery,"pageInfo");
			}
		},
		//Fix for WID-343
		showModifiedUrl: function(modUrl) {
			if (window.history && history.replaceState)
				history.replaceState(null, document.title, modUrl);
			else if ((/MSIE/).test(navigator.userAgent)) {
				var ampInHashIndex = 0, hashString = window.location.hash, patt1 = new RegExp("(\&st_refDomain=?)[^\&|]+"),
					patt2 = new RegExp("(\#st_refDomain=?)[^\&|]+"), hRef = document.location.href;
				if(patt1.test(hRef)) {
					ampInHashIndex = hashString.indexOf('&st_refDomain');
					window.location.hash = hashString.substr(0, ampInHashIndex);
				} else if(patt2.test(hRef))
					window.location.replace("#");
			} else {
				document.location.replace(modUrl);
			}
		},
		//Fix for WID-343
		getRefDataFromUrl: function(url) {
			var patt = new RegExp("st_refDomain="), tempDomain = '', tempQuery = '', result = [];

			if(patt.test(url)) {
				tempDomain = url.match(/(st_refDomain=?)[^\&|]+/g);
				result.push(tempDomain[0].split('=')[1]);

				tempQuery = url.match(/(st_refQuery=?)[^\&|]+/g);
				result.push(tempQuery[0].replace('st_refQuery=', ''));
			}

			return result;
		},
		//Fix for WID-343
		removeRefDataFromUrl: function(url) {
			var urlWoRefdomain = '',
				obj = '',
				patt1 = new RegExp("(\&st_refDomain=?)[^\&|]+"),
				patt2 = new RegExp("(\#st_refDomain=?)[^\&|]+");

			if(patt1.test(url)) {
				urlWoRefdomain = url.replace(/\&st_refDomain=(.*)/g,'');
			} else if(patt2.test(url)) {
				urlWoRefdomain = url.replace(/\#st_refDomain=(.*)/g,'');
			} else {
				urlWoRefdomain = url;
			}

			return urlWoRefdomain;
		},
		setPublisher: function(publisherKey) {
			// TODO: Add Validation
			stlib.data.set("publisher",publisherKey,"pageInfo");
			stlib.data.publisherKeySet = true;
		},
		setSource: function(src, options) {
			// TODO: Add Validation
			var source = "";
			// Inside widget logging
			if (options) {
				if (options.toolbar) {
					source = "toolbar"+src;
				} else if (options.page && options.page != "home" && options.page != "") {
					source = "chicklet"+src;
				} else {
					source = "button"+src;
				}
			}
			// Outside widget logging
			else {
				// can be share5x, share4x, chicklet, fastshare, mobile
				source = src;
			}
			stlib.data.set("source",source,"shareInfo");
		},
		set: function(key, value, table) {
			if (typeof(value) == "number" || typeof(value) == "boolean") {
				stlib.data[table][key] = value;
			} else if (typeof(value) == "undefined" || value == null) {
			} else {
//				_$d1("Stripping HTML: " + key + ": " + value.replace(/<[^<>]*>/gi, " "));
//				_$d1("decodeURI: " + key + ": " + decodeURI(value.replace(/<[^<>]*>/gi, " ")));
//				_$d1("Escape percent: " + key + ": " + decodeURI(value.replace(/<[^<>]*>/gi, " ")).replace(/%/gi, "%25"));
//				_$d1("Decoding: " + key + ": " + decodeURIComponent(decodeURI(value.replace(/<[^<>]*>/gi, " ")).replace(/%/gi, "%25")));
//				_$d1("Encoding: " + key + ": " + encodeURIComponent(decodeURIComponent(decodeURI(value.replace(/<[^<>]*>/gi, " ")).replace(/%/gi, "%25"))));
				stlib.data[table][key] = encodeURIComponent(decodeURIComponent(unescape(value.replace(/<[^<>]*>/gi, " ")).replace(/%/gi, "%25")));
				// These might have url encoded data
				if (key=="url" /*|| key=="sourceURL"*/ || key=="location" || key=="image") {
					try {
						stlib.data[table][key] = encodeURIComponent(decodeURIComponent(decodeURI(value.replace(/<[^<>]*>/gi, " ")).replace(/%/gi, "%25")));
					} catch (e) {
						stlib.data[table][key] = encodeURIComponent(decodeURIComponent(unescape(value.replace(/<[^<>]*>/gi, " ")).replace(/%/gi, "%25")));
					}
				}
			}
		},
		get: function(key, table) {
			try {
				if (stlib.data[table] && stlib.data[table][key])
					return decodeURIComponent(stlib.data[table][key]);
				else
					return false;
			}catch(e){
				return false
			}
		},
		unset: function(key, table) {
			if (stlib.data[table] && typeof(stlib.data[table][key])!="undefined")
				delete stlib.data[table][key];
		},
                bindEvent: function(element, eventName, eventHandler) {
                    if (element.addEventListener) {
                        element.addEventListener(eventName, eventHandler, false);
                    } else if (element.attachEvent) {
                        element.attachEvent('on' + eventName, eventHandler);
                    }
                },
                debug: function(endpoint, event) {
                  stlib.data.init();
                  var a = stlib.data.pageInfo;
                  var c = "";
                  var b;
                  for (b in a) {
                      c += b + "=" + a[b] + "&"
                  }
                  c = c.substring(0, c.length - 1);

                  var loggerUrl = "https://l.sharethis.com/";
                  loggerUrl += endpoint;
                  loggerUrl += "?event=" + event;
                  loggerUrl += "&" + c;

                  var e = new Image(1, 1);
                  e.src = loggerUrl;
                  e.onload = function() {
                      return
                  };
                },
                hostname: function(url) {
                  var a;
                  if (url == null) {
                    url = st.href;
                  }
                  a = document.createElement('a');
                  a.setAttribute('href', url);
                  return a.hostname;
                },
                protocol: function(url) {
                  var a;
                  if (url == null) {
                    url = st.href;
                  }
                  a = document.createElement('a');
                  a.setAttribute('href', url);
                  return a.protocol;
                },
                parseCookie: function (name, cookie) {
                  var values = cookie.match('(^|;)\\s*' + name + '\\s*=\\s*([^;]+)');
                  return values ? values.pop() : null;
                },
                writeCookie: function(name, value, max_age)  {
                  if (!max_age) {
                    max_age = 33696000
                  }
                  var host = (window && window.location && window.location.hostname) || '';
                  var parts = host.split('.');
                  var domain = "";
                  if (parts.length > 1) {
                    domain = "domain=." + parts.slice(-2).join('.');
                  }
                  var samesite_secure = "";
                  try {
                    document.cookie = "st_samesite=1;SameSite=None;Secure";
                    if (stlib.data.parseCookie("st_samesite", document.cookie)) {
                      samesite_secure = "SameSite=None;Secure"
                      document.cookie = "st_samesite=1;max-age=0;SameSite=None;Secure";
                    }
                  } catch (e) {}
                  document.cookie = name + "=" + value + ";" + domain + ";path=/;max-age=" + max_age + ";" + samesite_secure;
                },
                setConsent: function(consent) {
                    for(var consent_key in consent) {
                         stlib.data.set(consent_key,consent[consent_key],"pageInfo");
                    }
                },
                getEUConsent: function (c) {

                  function once(fn, context) { 
                    var result;
                    return function() { 
                      if(fn) {
                        result = fn.apply(context || this, arguments);
                        fn = null;
                      }
                      return result;
                    };
                  }
        
                  var done = once(c);

                  // set usprivacy first if we have it
                  var usprivacy = stlib.data.parseCookie("usprivacy", document.cookie);
                  if (usprivacy) {
                    stlib.data.setConsent({
                      usprivacy: usprivacy
                    });
                  }

                  // keep track of how long it takes to get consent
                  var start = Date.now();

                  var useCookie = once(function() {
        
                    // check for first party cookies
                    var euconsent_v2 = stlib.data.parseCookie("euconsent-v2", document.cookie);
                    if (euconsent_v2 !== null) {
                      stlib.data.setConsent({
                        gdpr_consent: euconsent_v2,
                        gdpr_domain: document.location.hostname,
                        gdpr_method: "cookie"
                      });
                    }
                    done();
                  });

                  if (typeof window.__tcfapi == "function") {

                    // fallback to cookie in case the tcf api is too slow or unavailable
                    var timeout = setTimeout(useCookie, 5000);
        
                    // first we try to get the data from the cmp
                    // wrap in a try catch since we don't control the tcfapi code on page
                    try {
                      window.__tcfapi("getTCData", 2, function (data) {
                        if (data && data.tcString) {
                          var gdpr_domain = (data.isServiceSpecific)
                            ? document.location.hostname : ".consensu.org";
                          stlib.data.setConsent({
                            consent_duration: Date.now() - start,
                            gdpr_consent: data.tcString,
                            gdpr_domain: gdpr_domain,
                            gdpr_method: "api"
                          });
                          clearTimeout(timeout);
                          done();
                        } else {
        
                          // fallback to cookie if there is no data
                          useCookie();
                        }
                      });
                    } catch (e) {
        
                      // fallback to cookie if there is an error
                      useCookie();
                    }
                  } else {
        
                    // fallback to cookie if the tcfapi doesn't exist
                    useCookie();
                  }
                }
	};

	stlib.data.resetData();
}
stlib.comscore = {
  load: function() {
      var ref=document.referrer;
      var lurl = "https://sb.scorecardresearch.com/";
      lurl+="b?c1=7&c2=8097938&rn=" +Math.round(Math.random() * 2147483647 )+ "&c7=" + encodeURIComponent(document.location.href)+ "&c3=8097938"+ "&c8="+encodeURIComponent(document.title)+ ( (ref)? "&c9="+encodeURIComponent(document.referrer) :  "" )+ "&cv=2.2"+ "&cs=js";
      var logger = new Image(1,1);
      logger.src = lurl;
      logger.onload = function(){return;};
  }
}
stlib.hash = {
	doNotHash: false,
	hashAddressBar: false,
	doNotCopy: false,
	prefix:"sthash",
	shareHash: "",
	incomingHash: "",
	validChars: ["1","2","3","4","5","6","7","8","9","0",
				"A","B","C","D","E","F","G","H","I","J",
				"K","L","M","N","O","P","Q","R","S","T",
				"U","V","W","X","Y","Z","a","b","c","d",
				"e","f","g","h","i","j","k","l","m","n",
				"o","p","q","r","s","t","u","v","w","x",
				"y","z"],
	servicePreferences: {
		linkedin: "param",
		stumbleupon: "param",
		bebo: "param"
	},
	hashDestination: function(destination) {
		if (destination == "copy") {return "dpuf";}
		var condensedString = destination.substring(0,2) + destination.substring(destination.length-2, destination.length);
		var increment = function(string, pos) {
			if(string.charCodeAt(pos) == 122) {
				return "a";
			}
			return String.fromCharCode(string.charCodeAt(pos) + 1);
		}
		return increment(condensedString, 0) + increment(condensedString, 1) + increment(condensedString, 2) + increment(condensedString, 3);
	},
	getHash: function() {
		var sthashFound = false;
		var sthashValue = "";
		var urlWithoutHash = document.location.href;
		urlWithoutHash = urlWithoutHash.split("#").shift();
		var paramArray = urlWithoutHash.split("?");
		if (paramArray.length > 1) {
			paramArray = paramArray[1].split("&");
			for (arg in paramArray) {
				try {
					if (paramArray[arg].substring(0, 6) == "sthash") {
						sthashFound = true;
						sthashValue = paramArray[arg];
					}
				} catch (err) {

				}
			}
			if (sthashFound) {
				return sthashValue;
			} else {
				return document.location.hash.substring(1);
			}
		} else {
			return document.location.hash.substring(1);
		}
	},
	stripHash: function(url) {
		var urlWithoutHash = url;
		urlWithoutHash = urlWithoutHash.split("#");
		if (urlWithoutHash.length > 1)
			return urlWithoutHash[1];
		else
			return "";
	},
	clearHash: function() {
		if (stlib.hash.validateHash(document.location.hash)) {
			var baseHref = document.location.href.split("#").shift();

			if (window.history && history.replaceState)
//				history.replaceState(null, "ShareThis", "#");
				history.replaceState(null, document.title, baseHref);
			else if ((/MSIE/).test(navigator.userAgent))
				window.location.replace("#");
			else
				document.location.hash = "";
		}
	},
	init: function() {
		var finalHash = "";
		var max = stlib.hash.validChars.length;
		for (var i=0;i<8;i++) {
			finalHash += stlib.hash.validChars[Math.random()*max|0];
		}
		if (stlib.hash.getHash() == "") {
			stlib.hash.shareHash = stlib.hash.prefix + "." + finalHash;
		} else {
			var splitHash = stlib.hash.getHash().split(".");
			var key = splitHash.shift();
			if (key == stlib.hash.prefix || key == stlib.hash.prefix) {
				stlib.hash.incomingHash = stlib.hash.getHash();
				stlib.hash.shareHash = stlib.hash.prefix + "." + splitHash.shift() + "." + finalHash;
			} else {
				stlib.hash.shareHash = stlib.hash.prefix + "." + finalHash;
			}
		}
		if (!stlib.hash.doNotHash && stlib.hash.hashAddressBar) {
			if (document.location.hash == "" || stlib.hash.validateHash(document.location.hash)) {
				if (window.history && history.replaceState)
					history.replaceState(null, "ShareThis", "#"+stlib.hash.shareHash + ".dpbs");
				else if ((/MSIE/).test(navigator.userAgent))
					window.location.replace("#"+stlib.hash.shareHash + ".dpbs");
				else
					document.location.hash = stlib.hash.shareHash + ".dpbs";
			}
		} else {
			stlib.hash.clearHash();
		}
		if (!stlib.hash.doNotHash && !stlib.hash.doNotCopy) {
			stlib.hash.copyPasteInit();
		}
		stlib.hash.copyPasteLog();
	},
	checkURL: function() {
		var destination = stlib.data.get("destination", "shareInfo");
		var baseURL = stlib.hash.updateParams(destination);
		var shortenedDestination = "." + stlib.hash.hashDestination(destination);
		stlib.hash.updateDestination(shortenedDestination);
		if (!stlib.hash.doNotHash && typeof(stlib.data.pageInfo.shareHash) != "undefined") {
			var url = stlib.data.get("url", "shareInfo");
			var hash = stlib.hash.stripHash(url);
			if (stlib.hash.validateHash(hash) || hash == "") {
				if(typeof(stlib.hash.servicePreferences[destination]) != "undefined") {
					if(stlib.hash.servicePreferences[destination] == "param") {
						_$d1("Don't use hash, use params");
						_$d2(baseURL);
						if (baseURL.split("?").length > 1) {
							var parameterArray = baseURL.split("?")[1].split("&")
							var sthashExists = false;
							//for (arg in parameterArray) {
							for (var arg = 0; arg < parameterArray.length; arg++) {
								if (parameterArray[arg].split(".")[0] == "sthash") {
									sthashExists = true;
								}
							}
							if (sthashExists) {
								// Param was fixed by updateParams, dont need to add anything
								stlib.data.set("url",baseURL, "shareInfo");
							} else {
								// Param wasn't there, need to add it.
								stlib.data.set("url",baseURL + "&" + stlib.data.pageInfo.shareHash, "shareInfo");
							}
						} else {
							// There are no params, need to add the hash param
							stlib.data.set("url",baseURL + "?" + stlib.data.pageInfo.shareHash, "shareInfo");
						}
						if (destination == "linkedin") {	// shar url contains # which is an error in LinkedIn
							if (stlib.data.get("sharURL", "shareInfo") != "") {
								stlib.data.set("sharURL", stlib.data.get("url", "shareInfo"), "shareInfo");
							}
						}
					} else {
						_$d1("Using Hash");
						stlib.data.set("url",baseURL + "#" + stlib.data.pageInfo.shareHash, "shareInfo");
					}
				} else {
					_$d1("Not using custom destination hash type");
					stlib.data.set("url",baseURL + "#" + stlib.data.pageInfo.shareHash, "shareInfo");
				}
			}
		}
	},
	updateParams: function(destination) {
		var baseURL = stlib.data.get("url", "shareInfo").split("#").shift();
		var regex2a = /(\?)sthash\.[a-zA-z0-9]{8}\.[a-zA-z0-9]{8}/;
		var regex2b = /(&)sthash\.[a-zA-z0-9]{8}\.[a-zA-z0-9]{8}/;
		var regex1a = /(\?)sthash\.[a-zA-z0-9]{8}/;
		var regex1b = /(&)sthash\.[a-zA-z0-9]{8}/;
		if (regex2a.test(baseURL)) {
			baseURL = baseURL.replace(regex2a, "?" + stlib.data.pageInfo.shareHash);
		} else if (regex2b.test(baseURL)) {
			baseURL = baseURL.replace(regex2b, "&" + stlib.data.pageInfo.shareHash);
		} else if (regex1a.test(baseURL)) {
			baseURL = baseURL.replace(regex1a, "?" + stlib.data.pageInfo.shareHash);
		} else if (regex1b.test(baseURL)) {
			baseURL = baseURL.replace(regex1b, "&" + stlib.data.pageInfo.shareHash);
		}
		return baseURL;
	},
	updateDestination: function(destinationHash) {
		var regex2 = /sthash\.[a-zA-z0-9]{8}\.[a-zA-z0-9]{8}\.[a-z]{4}/;
		var regex1 = /sthash\.[a-zA-z0-9]{8}\.[a-z]{4}/;
		_$d_();
		_$d1("Updating Destination");
		if (regex2.test(stlib.data.pageInfo.shareHash)) {
			_$d2(stlib.data.pageInfo.shareHash.substring(0,24));
			stlib.data.pageInfo.shareHash = stlib.data.pageInfo.shareHash.substring(0,24) + destinationHash;
		} else if (regex1.test(stlib.data.pageInfo.shareHash)) {
			_$d2(stlib.data.pageInfo.shareHash.substring(0,15));
			stlib.data.pageInfo.shareHash = stlib.data.pageInfo.shareHash.substring(0,15) + destinationHash;
		} else {
			stlib.data.pageInfo.shareHash += destinationHash;
		}
	},
	validateHash: function(isValidHash) {
		var regex3 = /[\?#&]?sthash\.[a-zA-z0-9]{8}\.[a-zA-z0-9]{8}$/;
		var regex2 = /[\?#&]?sthash\.[a-zA-z0-9]{8}\.[a-zA-z0-9]{8}\.[a-z]{4}$/;
		var regex1 = /[\?#&]?sthash\.[a-zA-z0-9]{8}\.[a-z]{4}$/;
		var regex0 = /[\?#&]?sthash\.[a-zA-z0-9]{8}$/;
		return regex0.test(isValidHash) || regex1.test(isValidHash) || regex2.test(isValidHash) || regex3.test(isValidHash);
	},
	appendHash : function (url) {
		var hash = stlib.hash.stripHash(url);
		if (stlib.data.pageInfo.shareHash && (stlib.hash.validateHash(hash) || hash == "")) {
			url = url.replace("#"+hash,"") + "#" + stlib.data.pageInfo.shareHash;
		} else {
		}
		return url;
	},
	copyPasteInit: function() {
		var body = document.getElementsByTagName("body")[0];
		var replacement = document.createElement("div");
		replacement.id = "stcpDiv";
		replacement.style.position = "absolute";
		replacement.style.top = "-1999px";
		replacement.style.left = "-1988px";
		body.appendChild(replacement);
		replacement.innerHTML = "ShareThis Copy and Paste";
		var baseHref = document.location.href.split("#").shift();
		var hash = "#" + stlib.hash.shareHash;
		if (document.addEventListener) {
			body["addEventListener"]("copy",function(e){
				//TYNT CONFLICT FIX: do not copy if Tynt object exists
				if (typeof(Tynt)!="undefined"){
//					console.log("Tynt exists. Don't copy");
					return;
				}
//				console.log("Tynt doesn't exist. Proceed");

				//grab current range and append url to it
				var selection = document.getSelection();

				if (selection.isCollapsed) {
					return;
				}

				var markUp = selection.getRangeAt(0).cloneContents();
				replacement.innerHTML = "";
				replacement.appendChild(markUp);

				if (replacement.textContent.trim().length==0) {
				    return;
				}

				if((selection+"").trim().length==0) {
					//No text, don't need to do anything
				} else if (replacement.innerHTML == (selection+"") || replacement.textContent == (selection+"")) {
					//Fix for CNS FB:12969. Encode html data to avoid js script execution on content copy
					replacement.innerHTML = stlib.html.encode(stlib.hash.selectionModify(selection));
				} else {
					//Fix for CNS FB:12969. Encode html data to avoid js script execution on content copy
					replacement.innerHTML += stlib.html.encode(stlib.hash.selectionModify(selection, true));
				}
				var range = document.createRange();
				range.selectNodeContents(replacement);
				var oldRange = selection.getRangeAt(0);
			},false);
		} else if (document.attachEvent) {
			/*
			body.oncopy = function() {
				var oldRange = document.selection.createRange();
				replacement.innerHTML = oldRange.htmlText;
				try {
					var length = (oldRange.text).trim().length;
				} catch (e) {
					var length = (oldRange.text).replace(/^\s+|\s+$/g, '').length;
				}
				if(length==0) {
					//No text, don't need to do anything
				} else if (oldRange.htmlText == oldRange.text) {
					//Just text, treat normally
					replacement.innerHTML = stlib.hash.selectionModify(oldRange.text);
				} else {
					//Text and markup, special case
					replacement.innerHTML += stlib.hash.selectionModify(oldRange.text, true);
				}
				var range = document.body.createTextRange();
				range.moveToElementText(replacement);
				range.select();
				setTimeout(function() {oldRange.select();}, 1);
			};
			*/
		}
	},
	copyPasteLog: function() {
		var eventMethod = window.addEventListener ? "addEventListener" : "attachEvent";
		var messageEvent1 = eventMethod == "attachEvent" ? "oncopy" : "copy";
		var body = document.getElementsByTagName("body")[0];
		if(body){
			body[eventMethod](messageEvent1,function(e){
				var pass = true;
				stlib.data.resetShareData();
				stlib.data.set("url", document.location.href, "shareInfo");
				stlib.data.setSource("copy");
				stlib.data.set("destination", "copy", "shareInfo");
		    	stlib.data.set("buttonType", "custom", "shareInfo");

				if (typeof(Tynt)!="undefined"){
					// Log Tynt
					stlib.data.set("result", "tynt", "shareInfo");
					pass = false;
				}
				if (typeof(addthis_config)!="undefined") {
					// Log AddThis
					stlib.data.set("result", "addThis", "shareInfo");
					if (typeof(addthis_config.data_track_textcopy)=="undefined"||addthis_config.data_track_textcopy) {
						stlib.data.set("enabled", "true", "shareInfo");
						pass = false;
					} else {
						stlib.data.set("enabled", "false", "shareInfo");
					}
				}
			},false);
		}
	},
	logCopy: function(url, selection) {
		stlib.data.resetShareData();
	    stlib.data.set("url", url, "shareInfo");
	    stlib.data.setSource("copy");
    	stlib.data.set("destination", "copy", "shareInfo");
    	stlib.data.set("buttonType", "custom", "shareInfo");
    	if (selection)
    		stlib.data.set("copy_text", selection, "shareInfo");
    	stlib.sharer.share();
	},
	selectionModify: function(selection, anchorOnly) {
		selection = "" + selection;
		_$d_();
		_$d1("Copy Paste");
		var regex = /^((http|https):\/\/([a-z0-9!'\(\)\*\.\-\+:]*(\.)[a-z0-9!'\(\)\*\.\-\+:]*)((\/[a-z0-9!'\(\)\*\.\-\+:]*)*))/i;
		var regex2 = /^([a-z0-9!'\(\)\*\.\-\+:]*(\.)[a-z0-9!'\(\)\*\.\-\+:]*)((\/[a-z0-9!'\(\)\*\.\-\+:]*)*)/i;
		var regexPhoneNumberUS = /^\+?1?[\.\-\\)_\s]?[\\(]?[0-9]{3}[\.\-\\)_\s]?[0-9]{3}[\.\-_\s]?[0-9]{4}$|^[0-9]{3}[\.\-_\s]?[0-9]{4}$/;
		var regexPhoneNumberIndia = /^[0-9]{3}[\.\-_\s]?[0-9]{8}$/;
		var regexPhoneNumberBrazil = /^[0-9]{2}[\.\-_\s]?[0-9]{4}[\.\-_\s]?[0-9]{4}$/;
		var regexEmail = /[\-_\.a-z0-9]+@[\-_\.a-z0-9]+\.[\-_\.a-z0-9]+/i;
		var regex3 = /[\s@]/;
		var baseHref = document.location.href.split("#").shift();
		var hash = "#" + stlib.hash.shareHash;
		var anchorStr = "";
		var urlStr = "";
		var returnStr = selection;
		if (typeof(anchorOnly) == "undefined" && ((regex.test(selection) || regex2.test(selection)) && !regex3.test(selection.trim()))) { // the selection is a url
			_$d2("is Url");
			if (selection.match(/#/) == null || stlib.hash.validateHash(selection)) {
				urlStr = selection.split("#")[0] + hash + ".dpuf";
			} else {
				urlStr = selection;
			}
		} else {
			_$d2("is Not Url");
			if (document.location.hash == "" || (/^#$/).test(document.location.hash) || stlib.hash.validateHash(document.location.hash)) {
				urlStr = baseHref + hash + ".dpuf";
			} else {
				urlStr = document.location.href;
			}
			returnStr = selection;
			if (selection.length > 50) {
				if (!regexPhoneNumberUS.test(selection) && !regexPhoneNumberIndia.test(selection) && !regexPhoneNumberBrazil.test(selection) && !regexEmail.test(selection)) {		// don't add if an email or phone number
					returnStr += anchorStr;
				}
			}
		}
		if (selection.length > 500) {
			selection = selection.substring(0, 497) + "...";
		}
		stlib.hash.logCopy(urlStr, selection);
		return returnStr;
	}
};
/* Requires browser obj */
stlib.pump = function (destination, source, callback) {
	var that = this;
	this.isIframeReady = false;
	this.isIframeSending = false;
	
	this.getHash = function(url) {
		var mArray = url.split("#");
		mArray.shift();
		return mArray.join("#");
	}
	
	this.broadcastInit = function(destination) {
		this.destination = destination;
		_$d_('---------------------');
		_$d1("Initiating broadcaster:");
		_$d(this.destination);
	};
	this.broadcastSendMessage = function(message) {
		_$d_('---------------------');
		_$d1("Initiating Send:");
		if (this.destination === window) { // Iframe sends an event to the parent window
			if (stlib.browser.ieFallback) {
				//window.location.hash = message;
				window.location.replace(window.location.href.split("#")[0] + "#" + message);
				_$d2("child can't communicate with parent");
				return;
			}
			_$d2("Iframe to publisher: " + message);
			parent.postMessage("#" + message, document.referrer);
		} else { // The parent window sends an event to the iframe
			_$d2("Publisher to Iframe: " + message);
			if (stlib.browser.ieFallback) {
				if (this.destination.contentWindow) {
					this.destination.contentWindow.location.replace(this.destination.src + "#" + message);
					this.isIframeSending = true;
				}
				return;
			}
			this.destination.contentWindow.postMessage("#" + message, this.destination.src);
		}
	};
	this.receiverInit = function(source, callback) {
		_$d_('---------------------');
		_$d1("Initiating Receiver:");
		_$d(source);
		if (stlib.browser.ieFallback) {
			this.callback = callback;
			this.source = source;
			if (source === window) { // The iframe polls the hash value for any changes
				//window.location.hash = "";
				window.location.replace(window.location.href.split("#")[0] + "#");
				this.currentIframe = window.location.hash;
				
				var receiverName = "receiver" + stlib.functionCount;
				stlib.functions[receiverName] = function (callback) {
					if ("" != window.location.hash && "#" != window.location.hash) {
						var hash = window.location.hash;
						callback(hash);
						//window.location.hash = "";
						window.location.replace(window.location.href.split("#")[0] + "#");
					}
				};
				stlib.functionCount++;
				var callbackName = "callback" + stlib.functionCount;
				stlib.functions[callbackName] = callback;
				stlib.functionCount++;
				setInterval("stlib.functions['" + receiverName + "'](stlib.functions['" + callbackName + "'])", 200);
				
			} else { // The parent polls the iframe 
			/*
				var receiverName = "receiver" + stlib.functionCount;
				that.oldHash = that.getHash(source.src);
				stlib.functions[receiverName] = function (callback) {
					_$d1("ShareThis Publisher is polling: " + that.oldHash + ": " + (source.src));
					if (that.oldHash != that.getHash(source.src)) {
						that.oldHash = that.getHash(source.src);
						callback(hash);
					}
				};
				stlib.functionCount++;
				var callbackName = "callback" + stlib.functionCount;
				stlib.functions[callbackName] = callback;
				stlib.functionCount++;
				setInterval("stlib.functions['" + receiverName + "'](stlib.functions['" + callbackName + "'])", 200);
			*/
			}
			var eventMethod = window.addEventListener ? "addEventListener" : "attachEvent";
			var messageEvent = eventMethod == "attachEvent" ? "onmessage" : "message";
			// Listen to message from child window
			window[eventMethod](messageEvent,function(e) {
				if (source == window) {
				} else {
					if (e.origin.indexOf("sharethis.com") != -1) {
						if (e.data.match(/#Pinterest Click/))
							stlib.sharer.sharePinterest();
						if (e.data.match(/#Print Click/))
							stlib.sharer.stPrint();
					}
				}
			},false);
			return;
		}
		var eventMethod = window.addEventListener ? "addEventListener" : "attachEvent";
		var messageEvent = eventMethod == "attachEvent" ? "onmessage" : "message";
		// Listen to message from child window
		window[eventMethod](messageEvent,function(e) {
			if (source == window) {
				_$d1("arrived in iframe from:");
				_$d(e.origin);
				if (e.data.match(/#fragmentPump/) || e.data.match(/#Buttons Ready/) || e.data.match(/#Widget Ready/) || e.data.indexOf("#light")==0 || e.data.indexOf("#widget")==0 || e.data.indexOf("#popup")==0 || e.data.indexOf("#show")==0 || e.data.indexOf("#init")==0 || e.data.indexOf("#test")==0 || e.data.indexOf("#data")==0)			// Make sure data is our own
					callback(e.data);				
			} else {
				if (e.origin.indexOf("sharethis.com") != -1) {
					_$d1("arrived in parent from:");
					_$d(e.origin);
					if (e.data.match(/#fragmentPump/) || e.data.match(/#Buttons Ready/) || e.data.match(/#Widget Ready/) || e.data.indexOf("#light")==0 || e.data.indexOf("#widget")==0 || e.data.indexOf("#popup")==0 || e.data.indexOf("#show")==0 || e.data.indexOf("#init")==0 || e.data.indexOf("#test")==0 || e.data.indexOf("#data")==0)			// Make sure data is our own
						callback(e.data);
					else if (e.data.match(/#Pinterest Click/))
						stlib.sharer.sharePinterest();
					else if (e.data.match(/#Print Click/))
						stlib.sharer.stPrint();
				} else {
					_$d1("discarded event from:");
					_$d(e.origin);
				}
			}
		},false);			
	};
	
	this.broadcastInit(destination);
	this.receiverInit(source, callback);
};
/***************START JSON ENCODE/DECODE***************/
stlib.json = {
	c : {"\b":"b","\t":"t","\n":"n","\f":"f","\r":"r",'"':'"',"\\":"\\","/":"/"},
	d : function(n){return n<10?"0".concat(n):n},
	e : function(c,f,e){e=eval;delete eval;if(typeof eval==="undefined")eval=e;f=eval(""+c);eval=e;return f},
	i : function(e,p,l){return 1*e.substr(p,l)},
	p : ["","000","00","0",""],
	rc : null,
	rd : /^[0-9]{4}\-[0-9]{2}\-[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}$/,
	rs : /(\x5c|\x2F|\x22|[\x0c-\x0d]|[\x08-\x0a])/g,
	rt : /^([0-9]+|[0-9]+[,\.][0-9]{1,3})$/,
	ru : /([\x00-\x07]|\x0b|[\x0e-\x1f])/g,
	s : function(i,d){return "\\".concat(stlib.json.c[d])},
	u : function(i,d){
		var	n=d.charCodeAt(0).toString(16);
		return "\\u".concat(stlib.json.p[n.length],n)
	},
	v : function(k,v){return stlib.json.types[typeof result](result)!==Function&&(v.hasOwnProperty?v.hasOwnProperty(k):v.constructor.prototype[k]!==v[k])},
	types : {
		"boolean":function(){return Boolean},
		"function":function(){return Function},
		"number":function(){return Number},
		"object":function(o){return o instanceof o.constructor?o.constructor:null},
		"string":function(){return String},
		"undefined":function(){return null}
	},
	$$ : function(m){
		function $(c,t) { 
			t=c[m];
			delete c[m];
			try {
				stlib.json.e(c)
			} catch(z){c[m]=t;return 1;}
		};
		return $(Array)&&$(Object);
	},
	encode : function(){
		var	self = arguments.length ? arguments[0] : this,
			result, tmp;
		if(self === null)
			result = "null";
		else if(self !== undefined && (tmp = stlib.json.types[typeof self](self))) {
			switch(tmp){
				case	Array:
					result = [];
					for(var	i = 0, j = 0, k = self.length; j < k; j++) {
						if(self[j] !== undefined && (tmp = stlib.json.encode(self[j])))
							result[i++] = tmp;
					};
					result = "[".concat(result.join(","), "]");
					break;
				case	Boolean:
					result = String(self);
					break;
				case	Date:
					result = '"'.concat(self.getFullYear(), '-', stlib.json.d(self.getMonth() + 1), '-', stlib.json.d(self.getDate()), 'T', stlib.json.d(self.getHours()), ':', stlib.json.d(self.getMinutes()), ':', stlib.json.d(self.getSeconds()), '"');
					break;
				case	Function:
					break;
				case	Number:
					result = isFinite(self) ? String(self) : "null";
					break;
				case	String:
					result = '"'.concat(self.replace(stlib.json.rs, stlib.json.s).replace(stlib.json.ru, stlib.json.u), '"');
					break;
				default:
					var	i = 0, key;
					result = [];
					for(key in self) {
						if(self[key] !== undefined && (tmp = stlib.json.encode(self[key])))
							result[i++] = '"'.concat(key.replace(stlib.json.rs, stlib.json.s).replace(stlib.json.ru, stlib.json.u), '":', tmp);
					};
					result = "{".concat(result.join(","), "}");
					break;
			}
		};
		return result;
	},
	decode : function(input){
		if(typeof(input)=='string')
		{
			var data=null;
			try{if ( /^[\],:{}\s]*$/.test(input.replace(/\\(?:["\\\/bfnrt]|u[0-9a-fA-F]{4})/g, "@")
			 .replace(/"[^"\\\n\r]*"|true|false|null|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?/g, "]")	
			 .replace(/(?:^|:|,)(?:\s*\[)+/g, "")) ) {
			 	data=window.JSON && window.JSON.parse ? window.JSON.parse(input) : (new Function("return " + input))();
			 	return data;
			 }else{
			 	return null;
			 }}catch(err){}	
		}
	}
};
try{stlib.json.rc=new RegExp('^("(\\\\.|[^"\\\\\\n\\r])*?"|[,:{}\\[\\]0-9.\\-+Eaeflnr-u \\n\\r\\t])+?$')}
catch(z){stlib.json.rc=/^(true|false|null|\[.*\]|\{.*\}|".*"|\d+|\d+\.\d+)$/}
/***************END JSON ENCODE/DECODE***************/
/********************START LOGGING***********************/
/*
 * This handles logging
 */
stlib.logger = {
  loggerUrl: "https://l.sharethis.com/",
  l2LoggerUrl: "https://l2.sharethis.com/",
  productArray: new Array(),
  version: '',
  lang: 'en',
  isFpEvent: false,

  constructParamString: function() {
    
    // Pull all the parameters from the page the widget was on
    var p = stlib.data.pageInfo;
    var paramString = "";
    var param;

    for (param in p) {
      
      // the following line creates "param=value&"
      if (p[param] == null || p[param] === "" || p[param] == "ERROR") continue;
      paramString += param + "=" + p[param] + "&";
    }

    // Pull all the parameters related to the share
    p = stlib.data.shareInfo;
    for (param in p) {
      if (p[param] == null || p[param] === "" || p[param] == "ERROR") continue;
      paramString += param + "=" + p[param] + "&";
    }

    // add sop parameter
    paramString += "sop=false"

    // add fpestid if it exists
    var fpestid = stlib.data.parseCookie("fpestid", document.cookie);
    if (fpestid) {
      paramString += "&fpestid=" + fpestid;
    }

    // add description if it exists
    try {
      var elements = document.getElementsByTagName("meta");
      for (var i = 0; i < elements.length; i++) {
        var attribute = elements[i].getAttribute('property');
        if (attribute == null) {
          attribute = elements[i].getAttribute('name');
        }
        if (attribute == "twitter:description" || attribute == "og:description" || attribute == "description" || attribute == "Description") {
          var description = encodeURIComponent(elements[i].getAttribute('content'));
          paramString += "&description=" + description;
          break;
        }
      }
    } catch (e) {}

    return paramString
  },
  ibl: function() {
    var blacklist, domain, protocol, hostname, href, i, len;
    href = document.referrer;
    if (href) {
      hostname = stlib.data.hostname(href) || '';
      if (stlib.data.protocol) {
        protocol = stlib.data.protocol(href) || '';
        if (protocol == "android-app:") {
          return true;
        }
      }
      blacklist = ['aol', 'bing', 'bs.to', 'facebook', 'google', 'yahoo', 'yandex', document.location.hostname];
      for (i = 0, len = blacklist.length; i < len; i++) {
        domain = blacklist[i];
        if (hostname.indexOf(domain) > -1) {
          return true;
        }
      }
      var logUrl = stlib.logger.loggerUrl + "log?event=ibl&url=" + href;
      stlib.logger.logByImage("ibl", logUrl, null);
    }
    return true;
  },
  obl: function(e) {
    var href, prefix, ref;
    if ((e != null ? (ref = e.target) != null ? ref.tagName : void 0 : void 0) === 'A') {
      href = e.target.getAttribute('href') || '';
      prefix = href.slice(0, href.indexOf(':'));
      if (href.slice(0, 4) === 'http' && e.target.hostname !== document.location.hostname) {
        var logUrl = stlib.logger.loggerUrl + "log?event=obl&url=" + href;
        stlib.logger.logByImage("obl", logUrl, null);
      }
    }
    return true;
  },
  getGDPRQueryString: function() {
    var gdpr_consent = stlib.data.get("gdpr_consent", "pageInfo");
    var gdpr_domain = encodeURIComponent(stlib.data.get("gdpr_domain", "pageInfo"));
    var gdpr_method = stlib.data.get("gdpr_method", "pageInfo");
    var gdpr_query_str = "";
    if (gdpr_consent) {
      gdpr_query_str += "&gdpr_consent=" + gdpr_consent;
    }
    if (gdpr_domain) {
      gdpr_query_str += "&gdpr_domain=" + gdpr_domain;
    }
    if (gdpr_method) {
      gdpr_query_str += "&gdpr_method=" + gdpr_method;
    }
    return gdpr_query_str;
  },

  loadPixelsAsync: function(res) {
    if (typeof(stlib.product) !== "undefined") {
      if ((stlib.product == "ecommerce") ||
         (stlib.product == "dos2") ||
         (stlib.product == "feather") ||
         (stlib.product == "simple") ||
         (stlib.product == "simpleshare") ||
         (stlib.product == "simple-share-pro")) {
        return;
      }
    }
    if (typeof(res) !== "undefined") {
        if (res.status === "true") {
          // set stid
          stlib.data.set("stid", res.stid, "pageInfo")

          // fire the pixel
          var pxcel_url = "https://t.sharethis.com/1/d/t.dhj?rnd=" +
            (new Date()).getTime() +
            "&cid=c010&dmn="+
            window.location.hostname +
            stlib.logger.getGDPRQueryString();
          var $el = document.createElement('script');
          $el.async = 1;
          $el.src = pxcel_url;
          $el.id = "pxscrpt";
          var first = document.getElementsByTagName('script')[0];
          first.parentNode.insertBefore($el, first);
        }

        // run dmd script if indicated in response
        if (res.dmd === "true") {
          var f = function (w, d, s, m, n, t) {
            w[m] = w[m] || {
              init: function () { (w[m].q = w[m].q || []).push(arguments); }, ready: function (c) {
                if ('function' != typeof c) { return; } (w[m].c = w[m].c || []).push(c); c = w[m].c;
                n.onload = n.onreadystatechange = function () {
                  if (!n.readyState || /loaded|complete/.test(n.readyState)) {
                    n.onload = n.onreadystatechange = null;
                    if (t.parentNode && n.parentNode) { t.parentNode.removeChild(n); } while (c.length) { (c.shift())(); }
                  }
                };
              }
            }, w[m].d = 1 * new Date(); n = d.createElement(s); t = d.getElementsByTagName(s)[0];
            n.async=1;n.src='https://www.medtargetsystem.com/javascript/beacon.js?'+(Date.now().toString()).substring(0,4);n.setAttribute("data-aim",m);t.parentNode.insertBefore(n,t);
          }
          f(window, document, 'script', 'AIM');

          AIM.init('194-3051-2EAEFDBB', { 'onload_pageview': false });

          AIM.ready(function () {
            var stid = stlib.data.get("stid", "pageInfo");
            var url = window.location.href + '#estid=' + stid;
            AIM.pageview(url);
          });
        }

        try {

          // get the browser family
          let user_agent = navigator.userAgent;
          let browser_family = "";
          if (user_agent.match(/chrome|chromium|crios/i)) {
            browser_family = "chrome";
          } else if (user_agent.match(/firefox|fxios/i)) {
            browser_family = "firefox";
          }  else if (user_agent.match(/safari/i)) {
            browser_family = "safari";
          }

          // run lotame's panorama id code if indicated by the content rule
          // and we're on firefox or safari
          if(res.lotame === "true" && browser_family.match(/firefox|safari/i)) {
            !function() {

              // Callback that will be triggered after each call to sync()
              // and let you have access to the profile and/or panorama ids
              var syncCallback = function (profile) {
          
                  // sync the panorama id
                  var panorama_id = profile.getPanoramaId();
                  if (panorama_id && res.stid) {
                    var url = "https://sync.sharethis.com/panorama"
                    url += "?uid=" + encodeURIComponent(panorama_id)
                    url += "&stid=" + encodeURIComponent(res.stid)
                    stlib.logger.send(url)
                  }

              };
          
              var lotame_client_id = '16621';
              var lotame_tag_input = {
                  config: {
                      onProfileReady: syncCallback
                  }
              };
          
              // Lotame initialization
              var lotame_config = lotame_tag_input.config || {};
              var namespace = window['lotame_sync_' + lotame_client_id] = {};
              namespace.config = lotame_config;
              namespace.data = {};
              namespace.cmd = namespace.cmd || [];
            } ();

            window.lotame_sync_16621.cmd.push(function() {
              window.lotame_sync_16621.sync();
            });

            stlib.logger.js("https://platform-api.sharethis.com/panorama.js");
          }
        } catch (e) {
          // do nothing for now
        }

    }
  },

  send: function(url) {
    var img = new Image(1, 1);
    img.src = url;
    img.style.display = "none"
    img.onload = function() {};
    img.onerror = function() {};
  },

  js: function(url) {
    var el = document.createElement('script');
    el.async = 1;
    el.src = url;
    var first = document.getElementsByTagName('script')[0];
    first.parentNode.insertBefore(el, first);
  },

  logByImage: function(event, logUrl, callback) {
    
    // add consent params if they exist
    var gdpr_consent = stlib.data.get("gdpr_consent", "pageInfo");
    var gdpr_domain = stlib.data.get("gdpr_domain", "pageInfo");
    if (gdpr_consent) {
      logUrl += "&gdpr_consent=" + gdpr_consent;
    }
    if (gdpr_domain) {
      logUrl += "&gdpr_domain=" + gdpr_domain;
    }
    var gdpr_method = stlib.data.get("gdpr_method", "pageInfo");
    if (gdpr_method) {
      logUrl += "&gdpr_method=" + gdpr_method;
    }
    var usprivacy = stlib.data.get("usprivacy", "pageInfo");
    if (usprivacy) {
      logUrl += "&usprivacy=" + usprivacy;
    }

    // add fpestid if it exists
    var fpestid = stlib.data.parseCookie("fpestid", document.cookie);
    if (fpestid) {
      logUrl += "&fpestid=" + fpestid;
    }
    
    // add description if it exists
    try {
      var elements = document.getElementsByTagName("meta");
      for (var i = 0; i < elements.length; i++) {
        var attribute = elements[i].getAttribute('property');
        if (attribute == null) {
          attribute = elements[i].getAttribute('name');
        }
        if (attribute == "twitter:description" || attribute == "og:description" || attribute == "description" || attribute == "Description") {
          var description = encodeURIComponent(elements[i].getAttribute('content'));
          logUrl += "&description=" + description;
          break;
        }
      }
    } catch (e) {}

    var mImage = new Image(1, 1);
    mImage.src = logUrl + "&img_pview=true";
    mImage.onload = function () {
      return;
    };
    if (event == "pview") {
      stlib.logger.loadPixelsAsync(undefined);
    } else {
      callback? callback() : null;
    }
  },

  // TODO: (step 1) error checking on data
  // TODO: (step 2) convert params into a generic object, normalize or prepare before logging
  log : function(event, loggingUrl, callback, newEndpoint) {

    if(typeof(stlib.data.get("counter", "shareInfo")) != "undefined") {
      var count = 0;
      if (stlib.data.get("counter", "shareInfo")) {
        count = stlib.data.get("counter", "shareInfo");
      }
      stlib.data.set("ts" + new Date().getTime() + "." + count, "", "shareInfo");
      stlib.data.unset("counter", "shareInfo");
    } else {
      stlib.data.set("ts" + new Date().getTime(), "", "shareInfo");
    }

    if(event == 'widget') {
      var shortenedDestination = "." + stlib.hash.hashDestination(stlib.data.shareInfo.destination);
      stlib.hash.updateDestination(shortenedDestination);
    }

    //Fix for SAB-709
    if ( !loggingUrl || (loggingUrl != stlib.logger.loggerUrl && loggingUrl != stlib.logger.l2LoggerUrl)) {
      loggingUrl = stlib.logger.loggerUrl;
    }

    // Step 3: log data (iterate through objects)
    var logName = null;
    if (newEndpoint) {
      logName = event;
    } else {
      logName = (event == "pview") ? event : ((event == "debug") ? "cns" : "log");
    }
    stlib.data.getEUConsent(function(consent){
      if(event == "pview") {
        var logUrl = loggingUrl + logName + "?event="+event+  "&" + "version="+stlib.logger.version+ "&" + "lang="+stlib.logger.lang + "&" + stlib.logger.constructParamString();
      }else {
        var logUrl = loggingUrl + logName + "?event="+event +  "&" + stlib.logger.constructParamString();
      }
      var pview_had_consent = (stlib.data.get("gdpr_consent", "pageInfo")) ? true : false;
      stlib.data.set("pview_had_consent", pview_had_consent, "pageInfo");
      try {
        var client = new XMLHttpRequest();
        var res;
        client.open("GET", logUrl, true);
        client.withCredentials = true;
        client.timeout = 10000;
        client.onreadystatechange = function () {
          if (this.readyState == this.DONE) {
            try {
              res = JSON.parse(client.responseText);
              if (res.fpestid) {
                stlib.data.writeCookie("fpestid", res.fpestid, res.fpestid_maxage);
              }
              if (event == "pview") {
                /*
                // stop firing comscore beacon
                if (typeof (stlib.comscore) != "undefined") {
                  stlib.comscore.load();
                }
                */
                stlib.logger.loadPixelsAsync(res);
              } else {
                callback ? callback(): null;
              }
            } catch (e) {
              // responseText is empty for request timeout
              stlib.logger.logByImage(event, logUrl, callback);
            }
          }
        };
        client.send();
      } catch (err) { // some browsers don't support XMLHttpRequest
        stlib.logger.logByImage(event, logUrl, callback);
      }
    });
  },
  tcfapi_listener: function() {
    var start = Date.now();
    var interval = setInterval(function() {
      if (window.__tcfapi) {
        try {
          window.__tcfapi("addEventListener", 2, function(data) {
            if (data && data.eventStatus == "useractioncomplete") {
              stlib.data.set("gdpr_consent", data.tcString, "pageInfo");
              var gdpr_domain = (data.isServiceSpecific) 
                ? document.location.hostname : ".consensu.org";
              stlib.data.set("gdpr_domain", gdpr_domain, "pageInfo");
              stlib.data.set("gdpr_method", "api", "pageInfo");
              var url = stlib.logger.loggerUrl;
              url += "log?event=updated_consent";
              url += "&pview_had_consent=" + stlib.data.get("pview_had_consent", "pageInfo");
              stlib.logger.logByImage("updated_consent", url, null);
            }
          });
        } catch (e) {
          clearInterval(interval);
        }
      }
      if (Date.now() - start > 10000) {
        clearInterval(interval);
      }
    }, 1000);
  }()
};

/********************END LOGGING***********************/
/* 
 * This handles ajax requests
 */
if(typeof(stlib.ajax)=="undefined") { 
    stlib.ajax = {
            post: function(url, params, callback, async) {
                    var xmlHttp = new XMLHttpRequest();
                    if (callback) {
                            async ? (xmlHttp.onreadystatechange = callback) : null;
                    }
                    xmlHttp.open("POST", url, async);
                    xmlHttp.send(params);
                    if (callback) {
                            !async ? callback() : null;
                    }
            },
      get: function(url, callback) {
        try {
          var client = new XMLHttpRequest();
          client.open("GET", url, true);
          client.withCredentials = true;
          client.onreadystatechange = function () {
            if (this.readyState == this.HEADERS_RECEIVED) {
              callback ? callback() : null;
            }
          };
          client.send();
        } catch (err) { // some browsers don't support XMLHttpRequest
          var mImage = new Image(1, 1);
          mImage.src = url;
          mImage.onload = function () {
            return;
          };
          callback ? callback() : null;
        }
      }
    }
}
/* end of ajax */
stlib.logger.version = 'buttons.js'
var customProduct = 'widget'

if(typeof(stLight)=="undefined" && typeof(SHARETHIS)=="undefined"){ //make sure it isnt called over and over again
  var stWidgetVersion = false;

  if(typeof(switchTo5x)=="undefined") {
    stWidgetVersion = "4x"; // For Migration Phase 2 - by deafult widget will be 5xa
  }else{
    if(switchTo5x == false){
      stWidgetVersion = "4x";
    }
    if(switchTo5x == true){
      stWidgetVersion = "5xa";
    }
  }

	stLight=new function(){
		this.version=false;
		this.publisher=null;
		this.sessionID_time = (new Date()).getTime().toString();
		this.sessionID_rand = Number(Math.random().toPrecision(5).toString().substr(2)).toString();
		this.sessionID = this.sessionID_time + '.' + this.sessionID_rand;
		this.fpc=null;
		this.counter=0;
		this.readyRun=false;
		this.meta={
				hostname: document.location.host,
				location: document.location.pathname
		};
		this.loadedFromBar=false;
		this.clickCallBack=false;
	};

	stLight.loadDefault = function() {
    if (typeof(customProduct) == "undefined") {
		  this.product = "DOS2";
    } else{
      this.product = customProduct;
    }
		this.source = "DOS2";
		this.version = "st_insights.js";
	};

	stLight.options=function(options){
		this.loadDefault();
		// set custom publisher
		if(options && options.publisher){
			stLight.setPublisher(options.publisher);
		}

		// set custom ref domain
		if(options && options.refDomain){
			stLight.setRefDomain(options.refDomain);
		}

		// set custom product
    // calls setProduct but doesn't update stLight.product
		// deprecated: productArray
		stlib.logger.productArray = []
		if(options && options.product){
			stLight.setProduct(options.product);
		}
    else {
			stLight.setProduct(stLight.product);
		}

               // set copy and share options
               if(options && typeof(options.hashAddressBar) != "undefined") {
                        stlib.hash.hashAddressBar = options.hashAddressBar;
               }
               stlib.hash.doNotHash = stlib.hash.doNotCopy = false;
               if(options) {
                        options.doNotCopy = options.doNotHash = false;
               }

	        stlib.stLightOptionsObj = options;
	};

	stLight.onReady=function(){
		if(stLight.readyRun==true){
			return false;
		}

		stLight.loadFromScript();
		stLight.readyRun=true;
    stlib.data.init();
        stLight.fpc=stlib.data.get("fpc", "pageInfo");
		if(stLight.publisher==null){
			if(typeof(window.console)!=="undefined"){
				try{
					// console.debug("Please specify a ShareThis Publisher Key \nFor help, contact support@sharethis.com");
				}catch(err){}
			}
		}
		stLight.setProduct(stLight.product);

		//TODO: set this from the ref?
		stlib.logger.lang = 'en';

	};




        //Used only to generate widget and pview events logs.
	stLight.log=function(event){
		stlib.data.resetShareData();
		stlib.data.setSource(stLight.getSource());
		stlib.data.set("url", document.location.href, "shareInfo");
		stlib.data.set("title", document.title, "shareInfo");
		stlib.data.set("counter", stLight.counter++, "shareInfo");
		stlib.logger.log(event);
	};


	if(window.document.readyState=="completed"){
		stLight.onReady();
	}else{
		if (typeof(window.addEventListener) != 'undefined') {
			window.addEventListener("load", stLight.onReady, false);
		} else if (typeof(document.addEventListener) != 'undefined') {
			document.addEventListener("load", stLight.onReady, false);
		} else if (typeof window.attachEvent != 'undefined') {
			window.attachEvent("onload", stLight.onReady);
		}
	}


	stLight.setPublisher = function(publisher) {
	  stlib.data.setPublisher(publisher);
	  stLight.publisher=publisher;
	};

	stLight.setRefDomain = function(refDomain) {
	  stlib.data.setRefDomain(refDomain);
	};

	stLight.setProduct = function(product) {
	  this.product =  product;
	  stlib.data.set("product", product, "pageInfo");
	};

	stLight.getProduct = function() {
		return this.product;
	};

  stLight.getSource=function(){
    var source = 'share4x';
    if(stWidgetVersion == "5xa"){
      source = 'share5x';
    }
    //TODO: Get share bar version before buttons load
    return source;
  };

}

stLight.getUrlSearchParam = function() {
  var list = window.location.search.substring(1);
  return list.split("&");
}

stLight.getUrlQueryParams = function(url) {
  var params = {};
  var parts = url.replace(/[?&]+([^=&]+)=([^&]*)/gi,
  function(m,key,value) {
		params[key] = value;
  });
  return params;
}

stLight.getScriptSrcParams = function(scriptId){
  var s = document.getElementById(scriptId);
  if (s) {
    return stLight.getUrlQueryParams(s.src)
  }
}

stLight.setParams = function(params) {
	if (params) {
		if (params.refdomain) {
			stLight.setRefDomain(params.refdomain);
		}
		if (params.publisher) {
			stLight.setPublisher(params.publisher);
		}
		if (params.product) {
			stLight.setProduct(params.product);
		}
	}
}

stLight.loadFromScript = function() {
  // Load the url params from script "st_insights_js" src
  var params = stLight.getScriptSrcParams('st_insights_js');
  stLight.setParams(params)
}

stLight.loadFromWindowLocation = function() {
  var params = stLight.getUrlSearchParam();
  stLight.setParams(params)
}

//END OF light.js

stLight.onDomContentLoaded=function(){
  stLight.onReady();
;
};


stLight.domReady=function(){
	stLight.onReady();
};


st_showing=false;

stLight.clickSubscribers=[];
stLight.nonClickSubscribers=[];


if(window.document.readyState=="completed"){
	stLight.domReady();//domReady
}else{
	if (typeof(window.addEventListener) != 'undefined') {
		window.addEventListener("load", stLight.domReady, false);
	} else if (typeof(document.addEventListener) != 'undefined') {
		document.addEventListener("load", stLight.domReady, false);
	} else if (typeof window.attachEvent != 'undefined') {
		window.attachEvent("onload", stLight.domReady);
	}
}



//DOMContentLoaded
if(typeof(__st_loadLate)=="undefined"){
	if (typeof(window.addEventListener) != 'undefined') {
		window.addEventListener("DOMContentLoaded", stLight.onDomContentLoaded, false);
	} else if (typeof(document.addEventListener) != 'undefined') {
		document.addEventListener("DOMContentLoaded", stLight.onDomContentLoaded, false);
	}
} else {
	if (typeof(window.addEventListener) != 'undefined') {
		window.addEventListener("DOMContentLoaded", stLight.onDomContentLoadedLazy, false);
	} else if (typeof(document.addEventListener) != 'undefined') {
		document.addEventListener("DOMContentLoaded", stLight.onDomContentLoadedLazy, false);
	}
}


if(document.readyState == "complete" && stLight.readyRun==false){ //Keep at the end of the file
	//This is called after body is loaded so the domeready call would never get called, so call it here
	stLight.domReady();
}

  


//deprecated (only used in special cases: i.e. Forbes)  This will always get from ShareThis count service
var stButtons = stButtons || {};

stButtons.getCount=function(url,service,element){
  var flag=false;

  if(element && element!==null){
    while (element.childNodes.length >= 1 )
    {
      try{element.removeChild(element.firstChild );}catch(err){} //empty out old ones...
    }
  }
  // delay execution of these, so that async-buttons.js will show up
  ShareThisEvent.listen('on_async_buttons_load',function(){
    stButtons = async_buttons.stButtons;
    stButtons.cbQueue.push({"url":url,"service":service,"element":element});
    stButtons.getCountsFromService(url,service,element);
  },false);
};

stButtons.locateElements=function(clearChildren){
  ShareThisEvent.listen('on_async_buttons_load', function(){
    async_buttons.stButtons.locateElements(clearChildren);
  }, false);
};

var stWidget = stWidget || {};
if(typeof(stWidget.readyRun) == 'undefined'){
  stWidget.addEntry=function(options){
    ShareThisEvent.listen('on_async_buttons_load',function(){
      stWidget = async_buttons.stWidget;
      stWidget.addEntry(options);
    },false);
  };
};

stLight.subscribe=function(evnt,fun){
  ShareThisEvent.listen('on_async_buttons_load',function(){
    stButtonsLib.subscribe(evnt,fun);
  },false);
};

// set product and property for new buttons
if (window.__sharethis__) {
  stlib.setProduct(window.__sharethis__.product);
  stlib.setPublisher(window.__sharethis__.property);
}
var sop_pview_logged = typeof __stdos__ !== 'undefined' && __stdos__ !== null && __stdos__.onscriptload;
if (!sop_pview_logged && !stlib.onscriptload && document.URL.indexOf("edge.sharethis.com") == -1) {
  stlib.data.init();
  stlib.onscriptload = true;
  stlib.logger.log("pview", null);
}
stlib.logger.ibl();
stlib.data.bindEvent(document, "click", stlib.logger.obl);

/********************START SCRIPTLOADER***********************/
/* 
 * This handles on demand loading of javascript and CSS files
 */
stlib.scriptLoader = {
	loadJavascript : function(href,callBack){
		var loader = stlib.scriptLoader;
		loader.head=document.getElementsByTagName('head')[0];
		loader.scriptSrc=href;
		loader.script=document.createElement('script');
		loader.script.setAttribute('type', 'text/javascript');
		loader.script.setAttribute('src', loader.scriptSrc);
		loader.script.async = true;
		
		if(window.attachEvent && document.all) { //IE:
			loader.script.onreadystatechange=function(){
				if(this.readyState=='complete' || this.readyState=='loaded'){
					callBack();
				}
			};
		} else { //other browsers:
			loader.script.onload=callBack;
		}
		loader.s = document.getElementsByTagName('script')[0]; 
		loader.s.parentNode.insertBefore(loader.script, loader.s);
	},
	loadCSS : function(href,callBack) {
		_$d_();
		_$d1("Loading CSS: "  + href);
		var loader = stlib.scriptLoader;
		var cssInterval;
		loader.head=document.getElementsByTagName('head')[0];
		loader.cssSrc=href;
		loader.css=document.createElement('link');
		loader.css.setAttribute('rel', 'stylesheet');
		loader.css.setAttribute('type', 'text/css');
		loader.css.setAttribute('href', href);
		loader.css.setAttribute('id', href);
		setTimeout(function(){
			callBack();
			if(!document.getElementById(href)){
				cssInterval=setInterval(function(){
					if(document.getElementById(href)){
						clearInterval(cssInterval);
						callBack();
					}
				}, 100);
			}
		},100);
		loader.head.appendChild(loader.css);		
	}
};
/********************END SCRIPTLOADER***********************/
