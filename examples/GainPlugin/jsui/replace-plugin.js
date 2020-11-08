const fs = require("fs");
const path = require("path");
class ReplacePlugin {
  constructor(option) {
    console.log("options: ", option);
  }
  apply(compiler) {
    compiler.hooks.afterEmit.tap("ReplacePlugin", (compilation) => {
      const { options: {output: {path: dir, filename } } } = compilation;
      const file = path.join(dir, filename);
      let source = fs.readFileSync(file, "utf8");
      source = source.replace(/_setTimeout2\["default"\]/g, "setTimeout");
      fs.writeFileSync(file, source);
    });
  }
}

module.exports = ReplacePlugin;
