#include <iostream>
#include <ctime>
#include <windows.h>
#include <algorithm> 
#include <random>  
#include <iterator>
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include <d3d9.h>
#include <tchar.h>
#include <misc/cpp/imgui_stdlib.h>

void sup();
void DPS();
void tank();

void apex();

void vanguard();
void duelist();
void strategist();


void clickyclacky();

ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


// Data
static LPDIRECT3D9              g_pD3D = nullptr;
static LPDIRECT3DDEVICE9        g_pd3dDevice = nullptr;
static bool                     g_DeviceLost = false;
static UINT                     g_ResizeWidth = 0, g_ResizeHeight = 0;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void ResetDevice();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Main code
int main(int, char**)
{
	// Make process DPI aware and obtain main monitor scale
	ImGui_ImplWin32_EnableDpiAwareness();
	float main_scale = ImGui_ImplWin32_GetDpiScaleForMonitor(::MonitorFromPoint(POINT{ 0, 0 }, MONITOR_DEFAULTTOPRIMARY));

	// Create application window
	WNDCLASSEXW wc = { sizeof(wc), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"ImGui Example", nullptr };
	::RegisterClassExW(&wc);
	HWND hwnd = ::CreateWindowW(wc.lpszClassName, L"Dear ImGui DirectX9 Example", WS_OVERLAPPEDWINDOW, 100, 100, (int)(1280 * main_scale), (int)(800 * main_scale), nullptr, nullptr, wc.hInstance, nullptr);

	// Initialize Direct3D
	if (!CreateDeviceD3D(hwnd))
	{
		CleanupDeviceD3D();
		::UnregisterClassW(wc.lpszClassName, wc.hInstance);
		return 1;
	}

	// Show the window
	::ShowWindow(hwnd, SW_SHOWDEFAULT);
	::UpdateWindow(hwnd);

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();

	// Setup scaling
	ImGuiStyle& style = ImGui::GetStyle();
	style.ScaleAllSizes(main_scale);        // Bake a fixed style scale. (until we have a solution for dynamic style scaling, changing this requires resetting Style + calling this again)
	style.FontScaleDpi = main_scale;        // Set initial font scale. (in docking branch: using io.ConfigDpiScaleFonts=true automatically overrides this for every window depending on the current monitor)

	// Setup Platform/Renderer backends
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX9_Init(g_pd3dDevice);

	// Load Fonts
	// - If fonts are not explicitly loaded, Dear ImGui will select an embedded font: either AddFontDefaultVector() or AddFontDefaultBitmap().
	//   This selection is based on (style.FontSizeBase * style.FontScaleMain * style.FontScaleDpi) reaching a small threshold.
	// - You can load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
	// - If a file cannot be loaded, AddFont functions will return a nullptr. Please handle those errors in your code (e.g. use an assertion, display an error and quit).
	// - Read 'docs/FONTS.md' for more instructions and details.
	// - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use FreeType for higher quality font rendering.
	// - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
	//style.FontSizeBase = 20.0f;
	//io.Fonts->AddFontDefaultVector();
	//io.Fonts->AddFontDefaultBitmap();
	//io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf");
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf");
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf");
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf");
	//ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf");
	//IM_ASSERT(font != nullptr);



	// Main loop
	bool done = false;
	while (!done)
	{
		// Poll and handle messages (inputs, window resize, etc.)
		// See the WndProc() function below for our to dispatch events to the Win32 backend.
		MSG msg;
		while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
				done = true;
		}
		if (done)
			break;

		// Handle lost D3D9 device
		if (g_DeviceLost)
		{
			HRESULT hr = g_pd3dDevice->TestCooperativeLevel();
			if (hr == D3DERR_DEVICELOST)
			{
				::Sleep(10);
				continue;
			}
			if (hr == D3DERR_DEVICENOTRESET)
				ResetDevice();
			g_DeviceLost = false;
		}

		// Handle window resize (we don't resize directly in the WM_SIZE handler)
		if (g_ResizeWidth != 0 && g_ResizeHeight != 0)
		{
			g_d3dpp.BackBufferWidth = g_ResizeWidth;
			g_d3dpp.BackBufferHeight = g_ResizeHeight;
			g_ResizeWidth = g_ResizeHeight = 0;
			ResetDevice();
		}

		// Start the Dear ImGui frame
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		// PLACE ALL FUNCTIONS HERE:

		clickyclacky();


		// NOT BELOW HERE:
		// Rendering
		ImGui::EndFrame();
		g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
		g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
		g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
		D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x * clear_color.w * 255.0f), (int)(clear_color.y * clear_color.w * 255.0f), (int)(clear_color.z * clear_color.w * 255.0f), (int)(clear_color.w * 255.0f));
		g_pd3dDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
		if (g_pd3dDevice->BeginScene() >= 0)
		{
			ImGui::Render();
			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
			g_pd3dDevice->EndScene();
		}
		HRESULT result = g_pd3dDevice->Present(nullptr, nullptr, nullptr, nullptr);
		if (result == D3DERR_DEVICELOST)
			g_DeviceLost = true;
	}

	// Cleanup
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	CleanupDeviceD3D();
	::DestroyWindow(hwnd);
	::UnregisterClassW(wc.lpszClassName, wc.hInstance);

	return 0;
}

// Helper functions

bool CreateDeviceD3D(HWND hWnd)
{
	if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == nullptr)
		return false;

	// Create the D3DDevice
	ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
	g_d3dpp.Windowed = TRUE;
	g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN; // Need to use an explicit format with alpha if needing per-pixel alpha composition.
	g_d3dpp.EnableAutoDepthStencil = TRUE;
	g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
	//g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
	if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
		return false;

	return true;
}

void CleanupDeviceD3D()
{
	if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = nullptr; }
	if (g_pD3D) { g_pD3D->Release(); g_pD3D = nullptr; }
}

void ResetDevice()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
	if (hr == D3DERR_INVALIDCALL)
		IM_ASSERT(0);
	ImGui_ImplDX9_CreateDeviceObjects();
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (wParam == SIZE_MINIMIZED)
			return 0;
		g_ResizeWidth = (UINT)LOWORD(lParam); // Queue resize
		g_ResizeHeight = (UINT)HIWORD(lParam);
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;
	}
	return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}



int RandomShitIDontNeed() {


	srand(time(NULL));
	std::string name;
	std::string answer;

	std::cout << "Welcome to the Randomizer" << '\n';

	Sleep(500);

	while (true) {
		std::cout << "Which game are you playing?" << '\n';
		std::cout << "1. Overwatch | 2. Apex Legends | 3. Marvel Rivals" << '\n';
		std::cin >> name;
		std::cout << '\n';


		if (name == "1") {

			std::string answer;
			std::string number;

			while (true) {

				std::cout << "Pick a number for the role you want randomized" << '\n' << '\n' << "1. Tank | 2. DPS | 3. Support" << '\n' << '\n';
				std::cin >> number;

				if (number == "1" || number == "Tank" || number == "tank") {

					tank();

				}
				else if (number == "2" || number == "DPS" || number == "dps") {

					DPS();

				}
				else if (number == "3" || number == "Support" || number == "support") {
					sup();
				}
				else {
					continue;
				}

				std::cout << '\n' << "Next random character?" << '\n' << "Yes or no?";
				std::cin >> answer;

				if (answer == "no") {
					break;
				}
			}
		}

		if (name == "2") {

			apex();

		}

		if (name == "3") {
			std::string number;
			std::string answer;


			while (true) {
				std::cout << "Pick a number for the role you want randomized" << '\n' << '\n' << "1. Vanguard | 2. Duelist | 3. Strategist" << '\n' << '\n';
				std::cin >> number;

				if (number == "1" || number == "Vanguard" || number == "vanguard") {
					vanguard();
				}
				else if (number == "2" || number == "Duelist" || number == "duelist") {
					duelist();
				}
				else if (number == "3" || number == "Strategist" || number == "strategist") {
					strategist();
				}
				else {
					continue;
				}

				std::cout << '\n' << "Next random character?" << '\n' << "Yes or no?";
				std::cin >> answer;

				if (answer == "no") {
					break;
				}
			}
		}

		std::cout << "Do you want to pick another game?" << '\n';
		std::cout << "Yes or No?" << '\n';
		std::cin >> answer;

		if (answer == "no") {
			return 0;
		}


	}





	return 0;
}

void sup() {

	std::string answer;
	std::string last;

	while (true) {

		int i = rand() % 8;

		std::string supp[] = { "Ana", "Baptiste", "B rigitte", "Illari", "Jetpack Cat", "Juno", "Kiriko", "Lifeweaver", "Lucio", "Mercy", "Mizuki", "Moira", "Wuyang", "Zenyatta" };

		if (supp[i] == last) {
			continue;
		}

		std::cout << supp[i] << '\n';

		std::cout << "Do you want to reroll your support?" << '\n';
		std::cout << "Yes or no?" << '\n';
		std::cin >> answer;

		if (answer == "no") {
			break;
		}

		last = supp[i];
	}
}

void tank() {

	std::string answer;
	std::string last;

	while (true) {

		int i = rand() % 8;

		std::string tank[] = { "Ramattra", "D.VA", "Domina", "Doomfist", "Hazard", "Junker Queen", "Mauga", "Orisa", "Reinhardty", "Roadhog", "Sigma", "Winston", "Wrecking Ball", "Zarya" };

		if (tank[i] == last) {
			continue;
		}

		std::cout << tank[i] << '\n';

		std::cout << "Do you want to reroll your tank?" << '\n';
		std::cout << "Yes or no?" << '\n';
		std::cin >> answer;

		if (answer == "no") {
			break;
		}

		last = tank[i];
	}
}

void DPS()
{
	std::string answer;
	std::string last;

	while (true) {

		int i = rand() % 8;

		std::string DPS[] = { "Sierra", "Anran", "Ashe", "Bastion", "Cassidy", "Echo", "Emre", "Freja", "Genji", "Hanzo", "Junkrat", "Mei", "Pharah", "Reaper", "Sojourn", "Soldier: 76", "Sombra", "Symmetra",
		"Torbjorn", "Tracer", "Vendetta", "Ventur", "Widowmaker" };

		if (DPS[i] == last) {
			continue;
		}

		std::cout << DPS[i] << '\n';

		std::cout << "Do you want to reroll your DPS?" << '\n';
		std::cout << "Yes or no?" << '\n';
		std::cin >> answer;

		if (answer == "no") {
			break;
		}

		last = DPS[i];
	}
}

void apex() {

	std::string answer;
	std::string last;

	while (true) {

		int i = rand() % 8;

		std::string apex[] = { "Alter", "Ash", "Axle", "Ballistic", "Bangalore", "Bloodhound", "Catalyst", "Casustic", "Conduit", "Crypto", "Fuse", "Gibraltar", "Horizn", "Lifeline", "Loba", "Mad Maggie",
		"Mirage", "Newcastle", "Octane", "Pathfinder", "Rampart", "Revenant", "Seer", "Sparrow", "Valkyrie", "Vantage", "Wattson", "Wraith" };

		if (apex[i] == last) {
			continue;
		}

		std::cout << apex[i] << '\n';

		std::cout << "Do you want to reroll your character?" << '\n';
		std::cout << "Yes or no?" << '\n';
		std::cin >> answer;

		if (answer == "no") {
			break;
		}

		last = apex[i];
	}
}


void vanguard() {

	std::string answer;
	std::string last;

	while (true) {

		int i = rand() % 8;

		std::string vanguard[] = { "Angela", "Bruce Banner", "Hulk", "Captain America", "Doctor Strange", "Emma Frost", "Groot", "Magneto", "Peni Parker", "Rogue", "The Thing", "Thor", "Venom" };

		if (vanguard[i] == last) {
			continue;
		}

		std::cout << vanguard[i] << '\n';

		std::cout << "Do you want to reroll your character?" << '\n';
		std::cout << "Yes or no?" << '\n';
		std::cin >> answer;

		if (answer == "no") {
			break;
		}

		last = vanguard[i];
	}

}

void duelist() {

	std::string answer;
	std::string last;

	while (true) {

		int i = rand() % 8;

		std::string duelist[] = { "Black Cat", "Black Panther", "Black Widow", "Blade", "Daredevil", "Deadpool", "Elsa Bloodstone", "Hawkeye", "Hela", "Human Torch", "Iron Fist", "Iron Man", "Magik"
		"Mister Fantastic", "Moon Knight", "Namor", "Phoenix", "Psylocke", "Scarlet Witch", "Spider-Man", "Squirrel Girl", "Star-Lord", "Storm", "The Punisher", "Winter Soldier", "Wolverine" };

		if (duelist[i] == last) {
			continue;
		}

		std::cout << duelist[i] << '\n';

		std::cout << "Do you want to reroll your character?" << '\n';
		std::cout << "Yes or no?" << '\n';
		std::cin >> answer;

		if (answer == "no") {
			break;
		}

		last = duelist[i];
	}
}


void strategist() {


	std::string answer;
	std::string last;

	while (true) {

		int i = rand() % 8;

		std::string strategist[] = { "White Fox", "Luna Snow", "Gambit", "Deadpool", "Invisible Woman", "Jeff the Land Shark", "Cloak & Dagger", "Adam Warlock" };

		if (strategist[i] == last) {
			continue;
		}

		std::cout << strategist[i] << '\n';

		std::cout << "Do you want to reroll your character?" << '\n';
		std::cout << "Yes or no?" << '\n';
		std::cin >> answer;

		if (answer == "no") {
			break;
		}

		last = strategist[i];
	}

}

std::string last;
std::string character;
int i = 1;
int game = -1;
int overwatch = -1;
int marvel = -1;
int siege = -1;

void clickyclacky() {


	ImGuiIO& io = ImGui::GetIO(); (void)io;


	static float f = 0.0f;
	static int counter = 0;

	ImGui::SetNextWindowPos(ImVec2(5, 644), ImGuiCond_FirstUseEver);

	ImGui::Begin("Color");                          // Create a window called "Hello, world!" and append into it.

	ImGui::Text("Here you can change the color of the background");               // Display some text (you can use a format strings too)

	ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

	if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
		counter++;
	ImGui::SameLine();
	ImGui::Text("counter = %d", counter);

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
	ImGui::End();


	ImGui::SetNextWindowPos(ImVec2(493, 52), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(332, 167), ImGuiCond_FirstUseEver);
	ImGui::Begin("Randomizer");



	if (game == -1) {
		ImGui::Text("Which game would you like to play?");
		if (ImGui::Button("Overwatch")) {
			game = 0;
			character = "";
		}
		ImGui::SameLine();
		if (ImGui::Button("Marvel Rivals")) {
			game = 1;
			character = "";
		}
		ImGui::SameLine();
		if (ImGui::Button("Rainbow Six Siege")) {
			game = 2;
			character = "";
		}
	}
	else if (game == 0) {
		ImGui::Text("Which Role do you want to randomize?");
		if (ImGui::Button("Tank")) {
			while (true) {
				overwatch = 1;
				std::string tanks[] = { "Ramattra", "D.VA", "Domina", "Doomfist", "Hazard", "Junker Queen", "Mauga", "Orisa", "Reinhardt", "Roadhog", "Sigma", "Winston", "Wrecking Ball", "Zarya" };
				int i = rand() % std::size(tanks);
				last = character;
				character = tanks[i];

				if (character != last) {
					break;
				}
			}
		}
		ImGui::SameLine();
		if (ImGui::Button("DPS")) {
			while (true) {
				overwatch = 1;
				std::string Dps[] = { "Sierra", "Anran", "Ashe", "Bastion", "Cassidy", "Echo", "Emre", "Freja", "Genji", "Hanzo", "Junkrat", "Mei", "Pharah", "Reaper", "Sojourn", "Soldier: 76", "Sombra", "Symmetra",
									  "Torbjorn", "Tracer", "Vendetta", "Venture", "Widowmaker" };
				int i = rand() % std::size(Dps);
				last = character;
				character = Dps[i];

				if (character != last) {
					break;
				}
			}
		}
		ImGui::SameLine();
		if (ImGui::Button("Support")) {
			while (true) {
				overwatch = 1;
				std::string Support[] = { "Ana", "Baptiste", "Brigitte", "Illari", "Jetpack Cat", "Juno", "Kiriko", "Lifeweaver", "Lucio", "Mercy", "Mizuki", "Moira", "Wuyang", "Zenyatta" };
				int i = rand() % std::size(Support);
				last = character;
				character = Support[i];

				if (character != last) {
					break;
				}
			}
		}

		if (character != "") {

			ImGui::Text(character.c_str());
			ImGui::Text("Do you want to reroll your character?");
		}
		if (ImGui::Button("Back to Main Menu")) {
			game = -1;
		}
	}
	else if (game == 1) {
		ImGui::Text("Which Role do you want to randomize?");
		if (ImGui::Button("Vanguard")) {
			marvel = 1;
			while (true) {

				std::string vanguard[] = { "Angela", "Bruce Banner", "Hulk", "Captain America", "Doctor Strange", "Emma Frost", "Groot", "Magneto", "Peni Parker", "Rogue", "The Thing", "Thor", "Venom" };
				int i = rand() % std::size(vanguard);
				last = character;
				character = vanguard[i];

				if (character != last) {
					break;
				}
			}
		}
		ImGui::SameLine();
		if (ImGui::Button("Duelist")) {
			marvel = 1;
			while (true) {

				std::string duelist[] = { "Black Cat", "Black Panther", "Black Widow", "Blade", "Daredevil", "Deadpool", "Elsa Bloodstone", "Hawkeye", "Hela", "Human Torch", "Iron Fist", "Iron Man", "Magik"
											"Mister Fantastic", "Moon Knight", "Namor", "Phoenix", "Psylocke", "Scarlet Witch", "Spider-Man", "Squirrel Girl", "Star-Lord", "Storm", "The Punisher",
											  "Winter Soldier", "Wolverine" };
				int i = rand() % std::size(duelist);
				last = character;
				character = duelist[i];

				if (character != last) {
					break;
				}
			}
		}
		ImGui::SameLine();
		if (ImGui::Button("Strategist")) {
			marvel = 1;
			while (true) {

				std::string duelist[] = { "White Fox", "Luna Snow", "Gambit", "Deadpool", "Invisible Woman", "Jeff the Land Shark", "Cloak & Dagger", "Adam Warlock" };
				int i = rand() % std::size(duelist);
				last = character;
				character = duelist[i];

				if (character != last) {
					break;
				}
			}
		}

		if (character != "") {

			ImGui::Text(character.c_str());
			ImGui::Text("Do you want to reroll your character?");
		}
		if (ImGui::Button("Back to Main Menu")) {
			game = -1;
		}
	}
	else if (game == 2) {
		ImGui::Text("Which side are you on?");
		
		if (ImGui::Button("Attackers")) {
			while (true) {
				std::string attack[] = { "Solid Snake", "Striker", "Rauora", "Deimos", "Ram", "Brava", "Grim", "Sens", "Osa", "Flores", "Zero", "Ace", "Iana", "Kali", "Amaru", "Nokk", "Gridlock", "Nomad",
											"Maverick", "Lion", "Finka", "Dokkaebi", "Zofia", "Ying", "Jackal", "Hibana", "Capitao", "Blackbeard", "Buck", "Sledge", "Thatcher", "Ash", "Thermite", "Montagne",
												"Twitch", "Blitz", "IQ", "Fuze", "Glaz" };
				int i = rand() % std::size(attack);
				last = character;
				character = attack[i];

				if (character != last) {
					break;
				}
			}
		}
		ImGui::SameLine();
		if (ImGui::Button("Defenders")) {
			while (true) {
				std::string defend[] = { "Denari", "Skopos", "Sentry", "Tubarao", "Fenrir", "Solis", "Azami", "Thorn", "Thunderbird", "Aruni", "Melusi", "Oryx", "Wamai", "Goyo", "Warden", "Mozzie", "Kaid",
											"Clash", "Maestro", "Alibi", "Vigil", "Ela", "Lesion", "Mira", "Echo", "Caveira", "Valkyrie", "Frost", "Mute", "Smoke", "Castle", "Pulse", "Doc", "Rook", "Jager", 
												"Bandit", "Tachanka", "Kapkan" };
				int i = rand() % std::size(defend);
				last = character;
				character = defend[i];

				if (character != last) {
					break;
				}
			}
		}
		if (character != "") {

			ImGui::Text(character.c_str());
			ImGui::Text("Do you want to reroll your character?");
		}
		if (ImGui::Button("Back to Main Menu")) {
			game = -1;
		}

	}


	ImGui::End();
}
