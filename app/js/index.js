var VID = 0xDEAD
var PID = 0xBEEF

var usb = require('usb');

// Find our device
var lpc = usb.findByIds(VID, PID);

// Open it
lpc.open();

// Get reference to INTF 0
var intf = lpc.interface(0);

// If the kernel driver is active. Detach it
if( intf.isKernelDriverActive() )
    intf.detachKernelDriver();

// Claim the interface
intf.claim();

intf.endpoints[0].startPoll(1, 128);
intf.endpoints[0].on('data', (dataBuf) => {
    let dataArr = Array.prototype.slice.call(new Uint8Array(dataBuf, 0, 64)); // convert buffer to array
    console.log( `RX: ${dataArr}` );
})
intf.endpoints[0].on('error', (err) => {
    intf.endpoints[0].stopPoll(null);
    console.log(`An error occured: ${err}`);
});
intf.endpoints[0].on('end', () => {
    console.log("Stream ended.");
    process.exit(0);
});