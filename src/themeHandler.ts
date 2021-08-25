
//const NativeTheme = require("react-native").NativeModules.ReactNativeThemeHandler;
import { NativeModules, NativeEventEmitter } from 'react-native';
const NativeTheme = NativeModules.ReactNativeThemeHandler;

export default class ThemeHandler {
    static setTheme = theme => {
        console.log("here");
        //NativeTheme.setTheme(theme);
        console.log("after");
    }

    static getTheme = () => {
        //return NativeTheme.getTheme();
    }
}