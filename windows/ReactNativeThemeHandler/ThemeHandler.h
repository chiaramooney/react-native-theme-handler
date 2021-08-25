#pragma once

#include "JSValue.h"
#include "NativeModules.h"
#include <string>

using namespace winrt;
using namespace winrt::Microsoft::ReactNative;
using namespace Windows::System;
using namespace Windows::UI;
using namespace Windows::UI::ViewManagement;
using namespace Windows::Storage;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

namespace winrt::ReactNativeThemeHandler
{

REACT_MODULE(ReactNativeModule, L"ReactNativeThemeHandler")
struct ReactNativeModule
{
    // See https://microsoft.github.io/react-native-windows/docs/native-modules for details on writing native modules

    REACT_INIT(Initialize)
    void Initialize(ReactContext const &reactContext) noexcept
    {
        m_reactContext = reactContext;
    }
    
    REACT_METHOD(setTheme)
    void setTheme(std::string theme) noexcept
    {
        if (auto rootElement = Window::Current().Content().as<Frame>()) {
            m_theme = theme;
            auto titleBar = ApplicationView::GetForCurrentView().TitleBar();
            if (theme == "dark") {
                rootElement.RequestedTheme(ElementTheme::Dark);
                titleBar.ForegroundColor(Colors::White());
                titleBar.BackgroundColor(Colors::Black());
            }
            if (theme == "light") {
                rootElement.RequestedTheme(ElementTheme::Light);
                titleBar.ForegroundColor(Colors::Black());
                titleBar.BackgroundColor(Colors::White());
            }
        }
    }

    REACT_METHOD(getTheme)
        std::string getTheme() noexcept
    {
        if (m_theme == "system") {
            if (ElementTheme::Default == ElementTheme::Light) {
                return "light";
            } else {
                return "dark";
            }
        } else {
            return m_theme;
        }

    }

    private:
        ReactContext m_reactContext{nullptr};
        std::string m_theme = "system";

};

} // namespace winrt::ReactNativeThemeHandler
