import "core-js/es6/map";
import "core-js/es6/set";
import "core-js/es6/weak-map";

const OPEN = "OPEN";
const CLOSED = "CLOSED";

const ws = {
  send: (e) => {
    __BlueprintNative__.sendToSocket(e + "\n");
  },
  OPEN: OPEN,
  CLOSED: CLOSED,
  readyState: "CLOSED",
  onmessage: (message) => {},
  onclose: () => {},
  onopen: () => {},
};

global.window = {};
  // inject hook into window.__REACT_DEVTOOLS_GLOBAK_HOOK__
  const devtools = require("react-devtools-core");
  global.__REACT_DEVTOOLS_GLOBAL_HOOK__ = global.window.__REACT_DEVTOOLS_GLOBAL_HOOK__;
  devtools.connectToDevTools({ websocket: ws });

const connectToDevTools = () => {
  global.__onSocketMessage__ = (data) => {
    ws.onmessage({ data: data });
  };
  global.__onSocketClose__ = () => {
    ws.readyState = ws.CLOSED;
    ws.onclose();
  };
  global.__onSocketOpen__ = () => {
    ws.readyState = ws.OPEN;
    ws.onopen();
  };
  console.log("devtools connected");
  setTimeout(() => {
    __BlueprintNative__.connect();
  }, 10);
};
export default connectToDevTools;
