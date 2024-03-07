#ifndef CONFIG_CLASS
#define CONFIG_CLASS

#include <cstdint>

/// @brief Class holding config information.
///
/// In the Config file the information needed for configuration of the window are stored. For example the width and height are stored within this header.
class Config {
	public:
		static const uint32_t WIDTH = 800; ///< @brief The standard width of the window
		static const uint32_t HEIGHT = 600; ///< @brief The standard height of the window
};

#endif