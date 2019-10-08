## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

.SILENT:

tests_run:
	@echo "STARTING CRITERION'S UNITS TESTS"
	@echo "----------------------------------------------------------------------------------------------------------------------"
	make -C ./datetime
	@echo "----------------------------------------------------------------------------------------------------------------------"
	make -C ./Host
	@echo "----------------------------------------------------------------------------------------------------------------------"
	make -C ./Kernel
	@echo "----------------------------------------------------------------------------------------------------------------------"
	make -C ./Ram
	@echo "----------------------------------------------------------------------------------------------------------------------"
	make -C ./CPU
	@echo "----------------------------------------------------------------------------------------------------------------------"
	@echo "UNITS TESTS END"

clean:
	make clean -C ./datetime
	make clean -C ./Host
	make clean -C ./Kernel
	make clean -C ./Ram
	make clean -C ./CPU

fclean:
	make fclean -C ./datetime
	make fclean -C ./Host
	make fclean -C ./Kernel
	make fclean -C ./Ram
	make fclean -C ./CPU

.PHONY: clean fclean all tests_run
