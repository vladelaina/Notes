/*
  WebFont Demo javascript
  
  (C) 2013-2020 High-Logic B.V.
  
  http://www.high-logic.com
*/

var haveErrors = false;
var haveOTLF   = false;

function Initialize() {
  if (fctrial) {
    AddError("This Web Font is created with a trial version of FontCreator. See the FontCreator User Manual about the limitations of exported fonts during the trial period.");
  }
  if (symbolfont) {
    AddError("Symbol fonts are legacy Windows fonts. They may not be supported by other operating systems, and word wrapping and spell check features won't work. Unicode fonts can contain symbols, so we recommend to convert your Symbol font to a Unicode font, unless you need to support old software. In FontCreator go to the main menu and select Tools -> Convert Font -> Convert to Unicode Font.");
  }
  BrowserCheck(otf.length > 0, colorfont);
  ProcessErrors();
  InitializeOpenTypeFeatures();
  InitializePreviewTextOptions();
  InitializeDirection();
  UpdatePreviewQuickPick(null);
}

function AddError(aError) {
  haveErrors = true;
  id = document.getElementById('errorlist');
  id.innerHTML += "<li>" + aError + "</li>";
  return false;
}

function ProcessErrors() {
  if (!haveErrors) {
    document.getElementById('errors').style.display = "none";
  }
  else {
    document.getElementById("nojserror").style.display = "none";
  }
}

function DetermineBrowser() {
  var browserstr = navigator.userAgent.toLowerCase();
  var result = Array();
  result["name"] = "unknown";
  result["fullname"] = "unknown";
  result["version"] = "unknown";
  if (match = browserstr.match("edge/([0-9]+)")) {
    result["name"] = "edge";
    result["fullname"] = "Microsoft Edge";
    result["version"] = match[1];
  }
  else if (match = browserstr.match("chrome/([0-9]+)")) {
    result["name"] = "chrome";
    result["fullname"] = "Google Chrome";
    result["version"] = match[1];
  }
  else if (match = browserstr.match("firefox/([0-9]+)")) {
    result["name"] = "firefox";
    result["fullname"] = "Mozilla Firefox";
    result["version"] = match[1];
  }
  else if (match = browserstr.match("opera/([0-9]+)")) {
    result["name"] = "opera";
    result["fullname"] = "Opera";
    result["version"] = match[1];
  }    
  else if (match = browserstr.match("safari/([0-9]+)")) {
    result["name"] = "safari";
    result["fullname"] = "Apple Safari";
    if (match = browserstr.match("version/([0-9\.]+)")) {
      result["version"] = match[1];
    }
  }
  else if (match = browserstr.match("msie ([0-9]+)")) {
    result["name"] = "ie";
    result["fullname"] = "Microsoft Internet Explorer";
    result["version"] = match[1];
  }  
  else if (match = browserstr.match("trident/([0-9]+).+; .*? rv:([0-9]+)")) {
    /* IE 11 and up */
    if (match[1] >= 7) {
      result["name"] = "ie";
      result["fullname"] = "Microsoft Internet Explorer";
      result["version"] = match[2];
    }
  }   
  return result;
}

function DetermineOS() {
  var browserstr = navigator.userAgent.toLowerCase();
  var result = Array();
  result["name"] = "unknown";
  result["version"] = "unknown";
  if (match = browserstr.match("windows.*? ([0-9\.]+);")) {
    result["name"] = "windows";
	result["version"] = match[1];
  }
  if (browserstr.indexOf("mac os x") > -1) {
    if (browserstr.indexOf("mobile") > -1) {
      result["name"] = "ios";
    } else {
      result["name"] = "osx";
    }
  }
  return result;
}

// converts HTML to text using Javascript
function html2text(html) {
var temp = document.createElement("div");
   temp.innerHTML = html;
   return temp.textContent || temp.innerText || "";
}

function BrowserCheck(aOTLF, aColor) {
 
  var browser = DetermineBrowser();
  var os = DetermineOS();
  var id = document.getElementById("errorlist");
  
//  return AddError(browser["name"] + " " + browser["version"] +" -> " + html2text(navigator.userAgent));

  switch (browser["name"]) {
    case "firefox" :
      if (aOTLF) {
	      if (browser["version"] < 4) {
            return AddError("You need at least FireFox 4 or a CSS 3.0 compatible browser in order to use OpenType layout features.");
          }
  	  }
	    if (aColor) {
	      if (browser["version"] < 32) {
            return AddError("You need at least Firefox 32 in order to use color fonts.");
          }
      }
    break;
    case "chrome" : 
      if (browser["version"] < 22) {
        return AddError("You need at least Chrome 22 or a CSS 3.0 compatible browser in order to use OpenType layout features.");
      }
  	  if (aColor) {
	      if (browser["version"] < 71) {
            return AddError("You need at least Chrome 71 in order to use color fonts.");
          }
      }
    break;
    case "edge" :
      // Should all work... 
    break;
    case "ie" : 
      if (aOTLF && (browser["version"] < 10)) {
        return AddError("You need at least Internet Explorer 10 or a CSS 3.0 compatible browser in order to use OpenType layout features.");
      }
	    if (aColor) {
		    if (browser["version"] < 11) {
              return AddError("You need at least Internet Explorer 11 in order to use color fonts.");
		    }
		    else {
              if (os["version"] < 6.3) {
                return AddError("You need at least Windows 8.1 to use color fonts with Internet Explorer. Alternatively you can use Firefox which supports color fonts since version 32 on all platforms.");
              }
          }
      }
    break;
    case "opera" : 
      if (browser["version"] < 15) {
        return AddError("You need at least Opera 15 or a CSS 3.0 compatible browser in order to use OpenType layout features.");
      }
      else {
        return AddWarning("Warning: This version of Opera might not support OpenType layout features.");
      }
      if (aColor) {
        return AddError("Opera does not support color fonts at least up to version 16.");
      }
    break;
    case "safari" : 
      if (os["name"] = "osx" ) {
        if (browser["version"] < 9.1) {
          return AddError("You need at least Safari 9.1 or a CSS 3.0 compatible browser in order to use OpenType layout features.");
        }
      }
      if (os["name"] = "ios" ) {
        if (browser["version"] < 9.3) {
          return AddError("You need at least Mobile Safari 9.3 or a CSS 3.0 compatible browser in order to use OpenType layout features.");
        }
      }
      if (aColor) {
        if (browser["version"] < 11) {
          return AddError("You need at least Safari 11 in order to use color fonts.");
        }
      }
    break;
    default :
      return AddError("Unable to determine your browser and/or version. OpenType layout features might not display correctly.");
    break;
  }
}

function UpdateFeatures() {
  var featurestring = "";
  var part = "";

  altval = document.getElementById("alternate").value;

  for (i = 0; i < otf.length; i++) {
    options_element = document.getElementById("otf_" + otf[i][0]);
    selected_element = options_element.querySelector(".is-selected");
    selected_value = selected_element.value;

    part = "";
    if (selected_value != 0) {
      part = "'" + otf[i][0] + "' " + (selected_value == 1 ? altval : "0");
    }
    if (part != "") {
      if (featurestring != "") {
        featurestring += ",";
      }
      featurestring += part;
    }
  }
  id = document.getElementById("preview");
  // Firefox 4+
  id.style.MozFontFeatureSettings = featurestring;
  // Chrome 20+ / Safari (OSX only)
  id.style.webkitFontFeatureSettings = featurestring;
  // Official CSS 3.0
  id.style.fontFeatureSettings = featurestring;
}

function SetAllFeatures(value) {
  for (i = 0; i < otf.length; i++) {
    options_element = document.getElementById("otf_" + otf[i][0]);
    element_to_select = options_element.querySelector("[value='" + value + "']");
    MarkAsSelected(element_to_select);
  }
  UpdateFeatures();
}

function InitializeOpenTypeFeatures() {
  id = document.getElementById("otfeatures");
  if (otf.length == 0) {
    id.innerHTML += "This font does not contain any OpenType layout features.";
    return;
  
  }
  id.innerHTML += "<input type='button' value='Default' onclick='SetAllFeatures(0)'/> ";
  id.innerHTML += "<input type='button' value='Enable all' onclick='SetAllFeatures(1)'/> ";
  id.innerHTML += "<input type='button' value='Disable all' onclick='SetAllFeatures(2)'/><hr/>";
  for (i = 0; i < otf.length; i++) {
    id.innerHTML += "<div class='feature'><span class='feature-options' id='otf_" + otf[i][0] + "'><button onclick='MarkAsSelected(this);UpdateFeatures();' value='0' class='is-selected'>Default</button><button onclick='MarkAsSelected(this);UpdateFeatures();' value='1' class=''>On</button><button onclick='MarkAsSelected(this);UpdateFeatures();' value='2' class=''>Off</button></span> <label>" + otf[i][0] + " - " + otf[i][1] + "</label></div>";
  }
  UpdateFeatures();
}

function InitializePreviewTextOptions() {
  var newOptions = "";
  const previewtext_select = document.getElementById("previewtext");
  for (i = 0; i < previewtext.length; i++) {
    newOptions += '<option value="' + i + '">' + previewtext[i].substring(0, 140); + '</option>';
  }
  previewtext_select.innerHTML = newOptions;
}

function InitializeDirection() {
  id = document.getElementById("direction");
  if (initialdir === 'RTL') {
    id.value = 'rtl';
    UpdateDirection('rtl');
  } else {
    id.value = 'ltr';
    UpdateDirection('ltr');
  }
}

function UpdatePreviewText(sender) {
  id = document.getElementById("preview");
  id.innerHTML = sender.value.replace(/\n/g, "<br/>");
}

function UpdatePreviewQuickPick(sender) {
  const input_element = document.getElementById("input");
  const value = document.getElementById('previewtext').value;
  input_element.value = previewtext[value];
  UpdatePreviewText(document.getElementById("input"));
}

function UpdateFontSize(sender) {
  id = document.getElementById("preview");
  id.style.fontSize = sender.value + "pt";
  id.style.lineHeight = sender.value + "pt";
}

function UpdateFontColorBG(sender) {
  id = document.getElementById("preview");
  id.style.background = "#" + sender.value;
}

function UpdateFontColorFG(sender) {
  id = document.getElementById("preview");
  id.style.color = "#" + sender.value;
}

function UpdateLanguage(sender) {
  id = document.getElementById("preview");
  id.lang = sender.value;
}

function UpdateAlternate(sender) {
  UpdateFeatures();
}

function UpdateDirection(sender) {
  id = document.getElementById("preview");
  id.style.direction = sender.value;
}

function MarkAsSelected(element) {
  element.parentElement.querySelector(".is-selected").classList.remove("is-selected");
  element.classList.add("is-selected");
}