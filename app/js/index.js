var VID = 0xDEAD
var PID = 0xBEEF
var sps = 0;

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

console.log(intf.endpoints[2]);
intf.endpoints[2].on('data', (dataBuf) => {
    // console.log(dataBuf);
    let dataArr = Array.prototype.slice.call(new Uint8Array(dataBuf, 0, 1024)); // convert buffer to array
    var sample_count = (((dataArr[1] & 0xFF) << 8) | (dataArr[0] & 0xFF));
    sps += sample_count;
    // console.log( `RX: ${sample_count}` );
})
intf.endpoints[2].on('error', (err) => {
    intf.endpoints[2].stopPoll(null);
    console.log(`An error occured: ${err}`);
});
intf.endpoints[2].on('end', () => {
    console.log("Stream ended.");
    process.exit(0);
});

setInterval(() => {
    console.log(`Samples per second: ${sps}`);
    sps = 0;
}, 1000);