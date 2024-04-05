Import("env")

print("Applying patch to support framework = arduino for NanoC6")
board_config = env.BoardConfig()
board_config.update("frameworks", ["arduino", "espidf"])
