var a = ['Congratulation: BeeFest{', 'N00b', 'onload', 'prompt', 'alert', 'Please enter the secret to the eternal life', 'TH15_15NT_TH3_FL4G', 'test', 'length', 'charCodeAt', 'charAt'];
(function(c, d) {
    var e = function(f) {
        while (--f) {
            c['push'](c['shift']());
        }
    };
    String.fromCharCode(++d);
}(a, 0x7b));
var b = function(c, d) {
    c = c - 0x0;
    var e = a[c];
    return e;
};
window["onload"] = function() {
    var c = this["prompt"];
    var d = this["alert"];
    var e = String['fromCharCode'];
    var password = prompt("Please enter secret to eternal life", "TH15_15NT_TH3_FL4G");
    var g = function(h) {
        return h % 0x1 === 0x0;
    };
    // "NDMSCRTH" or digits or '_'
    if (/[NDMSCRTH1234567890_]/.test(password)) {
        // password length = 0x15
        if (password.length == 0x15) {
            var i = 0x0;
            for (var j = 0x0; j < password.length; j++) {
                i += password.charCodeAt(j);
            }
            // sum of password must be 0x598
            if (i == 0x598) {
                i = 0x0;
                for (var j = 0x0; j < password.length; j++) {
                    i ^= password.charCodeAt(j);
                }
                // xor of password's sum and password must be 0x26
                if (i == 0x26) {
                    // way too much constraint...
                    if (password.charAt(0xb) == 'T' && password.charAt(0x0) === password.charAt(0x5) && password.charAt(0x5) == password.charAt(0x8) && password.charCodeAt(0x0) + password.charCodeAt(0x5) + password.charCodeAt(0x8) == 0x93) {
                        if (password.charAt(0x6) == password.charAt(0xd) && password.charAt(0x10) == password.charAt(0x13) && password.charAt(0x13) == password.charAt(0x6)) {
                            if (g(password.charAt(0x0)) && g(password.charAt(0x5)) && g(password.charAt(0x8)) && g(password.charAt(0x6))) {
                                if (parseInt(password.charAt(0x6)) / 0x3 == parseInt(password.charAt(0x0))) {
                                    if (password.charCodeAt(0x1) + password.charCodeAt(0x2) == 0x92 && password.charCodeAt(0x1) + password.charCodeAt(0x3) == 0x7e) {
                                        if (parseInt(password.charAt(0x0)) - parseInt(password.charAt(0x5)) === 0x0 && parseInt(password.charAt(0x0)) - parseInt(password.charAt(0x5)) == parseInt(password.charAt(0x3))) {
                                            if (parseInt(password.charAt(0x8)) + parseInt(password.charAt(0x5)) + parseInt(password.charAt(0x6)) == password.charAt(0x9)) {
                                                if (String.fromCharCode(password.charCodeAt(0x1) - 0x1) == password.charAt(0x4)) {
                                                    if (password.charAt(0xb) == password.charAt(0x14) && String.fromCharCode(password.charCodeAt(0x14) - 0x1) == password.charAt(0xf) && String.fromCharCode(password.charCodeAt(0xf) - 0x1) == password.charAt(0x12)) {
                                                        alert("Congratulation: BeeFest{" + password + '}');
                                                    } else {
                                                        alert('N00b');
                                                    }
                                                } else {
                                                    alert('N00b');
                                                }
                                            } else {
                                                d('N00b');
                                            }
                                        } else {
                                            d('N00b');
                                        }
                                    } else {
                                        alert('N00b');
                                    }
                                } else {
                                    alert('N00b');
                                }
                            } else {
                                alert('N00b');
                            }
                        } else {
                            alert('N00b');
                        }
                    } else {
                        alert('N00b');
                    }
                } else {
                    alert('N00b');
                }
            } else {
                alert('N00b');
            }
        } else {
            alert('N00b');
        }
    } else {
        alert('N00b');
    }
};