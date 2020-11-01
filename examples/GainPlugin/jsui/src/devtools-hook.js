    global.window = {};
const devtools = require('react-devtools-core');
console.log("hook:: ", global.window.__REACT_DEVTOOLS_GLOBAL_HOOK__);
global.window.__REACT_DEVTOOLS_GLOBAL_HOOK__.on("operation", (op) => console.log("\n*****hook operation emitted: ", op))
global.window.__REACT_DEVTOOLS_GLOBAL_HOOK__.on("traceUpdates", (op) => console.log("\n****hook traceUpdates emitted: ", op))
global.window.__REACT_DEVTOOLS_GLOBAL_HOOK__.on("renderer", (op) => console.log("\n****hook renderer emitted: ", op))
global.window.__REACT_DEVTOOLS_GLOBAL_HOOK__.on("renderer-attached", (op) => console.log("\n****hook renderer-attached emitted: ", op))
global.__REACT_DEVTOOLS_GLOBAL_HOOK__ = global.window.__REACT_DEVTOOLS_GLOBAL_HOOK__;
console.log(global.window.__REACT_DEVTOOLS_ATTACH__);
export default devtools;

