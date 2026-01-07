#ifndef SETTINGS_H
#define SETTINGS_H

typedef struct settings_t settings_t;

typedef enum{
    EASY,
    NORMAL,
    HARD,
    CUSTOM
}GameMode;

/// @brief Get gamemode from settings
/// @param settings target
/// @return gamemode in settings
GameMode GetGameMode(settings_t *settings);

/// @brief get grid width
/// @param settings target
/// @return get grid width in number
int GetGridWidth(settings_t *settings);

/// @brief get grid height
/// @param settings target
/// @return get grid height in number
int GetGridHeight(settings_t *settings);

/// @brief get total mines 
/// @param settings target
/// @return total mines in number
int GetMineTotal(settings_t *settings);


/// @brief Set gamemode/difficulty in target using GameMode ENUMs
/// @param settings target
/// @param difficulty  target GameMode
void SetGameMode(settings_t *settings, GameMode difficulty);

/// @brief sets the width of target grid in settings
/// @param settings target
/// @param width width to set it to
void SetGridWidth(settings_t *settings, int width);

/// @brief sets the heigth of target grid in settings
/// @param settings target
/// @param height height to set it to
void SetGridHeight(settings_t *settings,int height);

/// @brief Set the total amount of mines in target settings
/// @param settings target
/// @param minecount amount of mines to set it to
void SetMineTotal(settings_t *settings, int minecount);

/// @brief Get grid grace size from target setting
/// @param settings target
/// @return grid grace size in number
int GetGridGrace(settings_t *settings);

/// @brief sets the grace size in target settings
/// @param settings target
/// @param Grace gracesize to set it to.
void SetGridGrace(settings_t *settings, int Grace);


/// @brief allocated memory and returns pointer for settings_t
/// @param difficulty to use default values in creation
/// @return pointer to memory allocated
settings_t *CreateSettings(GameMode difficulty);

/// @brief frees memory for target settings_t
/// @param settings target
void DestroySettings(settings_t *settings);
#endif //SETTINGS_H