#pragma once
#include <vector>
#include <string>

#include <wtypes.h>

enum class CustomKey;

enum ClientToggleSetting {
	Jingles,
	ColorblindMode,
	ChallengeTimer,
	SyncProgress,
	HighContrast,
};

enum ClientDropdownSetting {
	Collect,
	DisabledPuzzles,
};

enum ClientStringSetting {
	ApAddress,
	ApSlotName,
	ApPassword
};

enum ClientWindowMode {
	Disabled,			// Disable all user input. Used while loading and randomizing.
	PreConnect,		// Pending connection to AP and randomization.
	Randomized			// Connected to AP and randomized.
};

class ClientWindow {

public:

	// Creates the window singleton.
	static void create(HINSTANCE appInstance, int nCmdShow);

	// Gets the window singleton. Returns nullptr if create() has not been called yet.
	static ClientWindow* get();

	HWND getRootWindow() const { return hwndRootWindow; }

	// Save/load settings to/from a local file.
	void saveSettings();
	void loadSettings();

	// Shows an informational dialog box and blocks execution until it is dismissed.
	void showMessageBox(std::string message) const;

	// Shows a yes/no dialog and blocks execution until it is dismissed. Returns whether or not
	//   the user clicked yes.
	bool showDialogPrompt(std::string message) const;

	bool getSetting(ClientToggleSetting setting) const;
	void setSetting(ClientToggleSetting setting, bool value) const;

	std::string getSetting(ClientStringSetting setting) const;
	void setSetting(ClientStringSetting setting, std::string value) const;

	std::string getSetting(ClientDropdownSetting setting) const;
	void setSetting(ClientDropdownSetting setting, std::string value) const;

	void refreshKeybind(const CustomKey& customKey) const;

	// Sets the status message field.
	void setStatusMessage(std::string statusMessage) const;

	// Sets the "last error message" field.
	void setErrorMessage(std::string errorMessage) const;

	void setWindowMode(ClientWindowMode mode);

	void focusGameWindow();
	void focusClientWindow();

private:

	ClientWindow(HINSTANCE hAppInstance) : hAppInstance(hAppInstance) {}
	static ClientWindow* _singleton;

	void buildWindow();
	void addHorizontalRule(int& currentY);
	void addVersionDisplay(int& currentY);
	void addArchipelagoCredentials(int& currentY);
	void addGameOptions(int& currentY);
	void addKeybindings(int& currentY);
	void addPuzzleEditor(int& currentY);
	void addErrorMessage(int& currentY);

	void show(int nCmdShow);

	void focusAndHighlight(HWND hwndTextBox);
	void toggleCheckbox(int buttonId);

	std::string readStringFromTextBox(HWND hwndTextBox) const;
	void writeStringToTextBox(std::string, HWND hwndTextBox) const;

	std::string readStringFromDropdown(HWND hwndDropdown) const;

	void handleKeybind(const CustomKey& customKey);

	// Handles events generated by the client window. Note that we need a wrapper that grabs the
	//   singleton and calls the function on it so that we can use it as a parameter on the window
	//   class.
	LRESULT CALLBACK handleWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK singletonHandleWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
		return get()->handleWndProc(hwnd, message, wParam, lParam);
	}

	HINSTANCE hAppInstance;
	HWND hwndRootWindow;
	HWND hwndApLoadCredentials, hwndApConnect;
	HWND hwndStatusText, hwndErrorText;

	HWND hwndTEMPfocusWindow;

	ClientWindowMode currentWindowMode = ClientWindowMode::Disabled;

	std::map<ClientToggleSetting, int> toggleSettingButtonIds;
	std::map<ClientToggleSetting, HWND> toggleSettingCheckboxes;
	std::map<ClientDropdownSetting, int> dropdownIds;
	std::map<ClientDropdownSetting, HWND> dropdownBoxes;
	std::map<ClientStringSetting, HWND> stringSettingTextBoxes;
	std::map<CustomKey, HWND> customKeybindValues;
	std::map<CustomKey, HWND> customKeybindButtons;

	// HACK: Due to things like menu bar thickness, the working area of the root window won't
	//   actually be whatever we request. As such, we need to store the delta between the requested
	//   window size and the working area so that we can request a correctly-sized window.
	int windowWidthAdjustment;
	int windowHeightAdjustment;

};