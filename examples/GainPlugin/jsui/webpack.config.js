//const BundleAnalyzerPlugin = require('webpack-bundle-analyzer').BundleAnalyzerPlugin;
const ReplacePlugin = require('./replace-plugin');
module.exports = {
  entry: './src/index.js',
  output: {
    path: __dirname + '/build/js',
    filename: 'main.js',
    sourceMapFilename: "[file].map",
     devtoolModuleFilenameTemplate: info =>
    `webpack:///${info.absoluteResourcePath.replace(/\\/g, '/')}`
  },
  devtool: "source-map",
  plugins: [
    //new BundleAnalyzerPlugin()
    new ReplacePlugin()
  ],
  module: {
    rules: [
      {
        test: /\.(js|jsx)$/,
        exclude: /node_modules\/(?!react-devtools-core)/,
        use: ['babel-loader']
      },
      {
        test: /\.svg$/,
        exclude: /node_modules/,
        use: ['svg-inline-loader']
      },
      {
        test: /\.(png|jpeg|jpg|gif)$/,
        use: [
          {
            loader: 'url-loader',
            options: {
              limit: true,
              esModule: false
            },
          },
        ],
      },
    ]
  },
};
