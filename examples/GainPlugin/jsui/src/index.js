
// import "@babel/polyfill/noConflict";
import 'core-js/modules/es.set';
import 'core-js/modules/es.map';
import 'core-js/modules/es.weak-map';
console.log("new session-----------------");
// setTimeout(() => console.log("hello world"), 10);
setTimeout(function() {
  console.log("hello world");
}, 1000);
import reactDevtools from './devtools-hook';
const ws = {send: (e) => console.log("ws.send: ", e)};
import React from 'react';
import App from './App';
import Blueprint from 'juce-blueprint';
reactDevtools.connectToDevTools({websocket: ws});
ws.readyState = ws.OPEN = "open";
Blueprint.render(<App />, Blueprint.getRootContainer());
ws.onopen();
ws.onmessage({data: '{"event": "getProfilingStatus"}'});
ws.onmessage({data: '{"event":"updateConsolePatchSettings","payload":{"appendComponentStack":true,"breakOnConsoleErrors":false}}'});
ws.onmessage({data: '{"event":"setTraceUpdatesEnabled","payload":false}'});