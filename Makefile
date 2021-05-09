all:
	@echo "test, lib, clean"

test: lib 
	build/test_phobos2390_gb_tileset_utils
	
lib:
	@mkdir -p build
	@cd build; cmake ..
	@cd build; make

clean:
	@rm -rf build
