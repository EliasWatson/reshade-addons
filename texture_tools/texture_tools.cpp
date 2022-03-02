#define ImTextureID unsigned long long

#include <imgui.h>
#include <reshade.hpp>

using namespace reshade::api;

extern "C" __declspec(dllexport) const char* NAME = "Texture Tools";
extern "C" __declspec(dllexport) const char* DESCRIPTION = "Various tools to inspect and modify game textures";

static void draw_overlay(effect_runtime* runtime) {
    ImGui::TextUnformatted("Hello Reshade Overlay!");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID) {
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        if (!reshade::register_addon(hModule))
            return FALSE;
        reshade::register_overlay("TextureTools", draw_overlay);
        break;
    
    case DLL_PROCESS_DETACH:
        reshade::unregister_overlay("TextureTools", draw_overlay);
        reshade::unregister_addon(hModule);
        break;
    }

    return TRUE;
}
