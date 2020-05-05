# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.testSFML.Debug:
/Users/Yu/Documents/UtahMSD/Cmake/xcode/Debug/testSFML:\
	/Library/Frameworks/./sfml-graphics.framework/Versions/2.5.1/sfml-graphics\
	/Library/Frameworks/./sfml-window.framework/Versions/2.5.1/sfml-window\
	/Library/Frameworks/./sfml-system.framework/Versions/2.5.1/sfml-system
	/bin/rm -f /Users/Yu/Documents/UtahMSD/Cmake/xcode/Debug/testSFML


PostBuild.testSFML.Release:
/Users/Yu/Documents/UtahMSD/Cmake/xcode/Release/testSFML:\
	/Library/Frameworks/./sfml-graphics.framework/Versions/2.5.1/sfml-graphics\
	/Library/Frameworks/./sfml-window.framework/Versions/2.5.1/sfml-window\
	/Library/Frameworks/./sfml-system.framework/Versions/2.5.1/sfml-system
	/bin/rm -f /Users/Yu/Documents/UtahMSD/Cmake/xcode/Release/testSFML


PostBuild.testSFML.MinSizeRel:
/Users/Yu/Documents/UtahMSD/Cmake/xcode/MinSizeRel/testSFML:\
	/Library/Frameworks/./sfml-graphics.framework/Versions/2.5.1/sfml-graphics\
	/Library/Frameworks/./sfml-window.framework/Versions/2.5.1/sfml-window\
	/Library/Frameworks/./sfml-system.framework/Versions/2.5.1/sfml-system
	/bin/rm -f /Users/Yu/Documents/UtahMSD/Cmake/xcode/MinSizeRel/testSFML


PostBuild.testSFML.RelWithDebInfo:
/Users/Yu/Documents/UtahMSD/Cmake/xcode/RelWithDebInfo/testSFML:\
	/Library/Frameworks/./sfml-graphics.framework/Versions/2.5.1/sfml-graphics\
	/Library/Frameworks/./sfml-window.framework/Versions/2.5.1/sfml-window\
	/Library/Frameworks/./sfml-system.framework/Versions/2.5.1/sfml-system
	/bin/rm -f /Users/Yu/Documents/UtahMSD/Cmake/xcode/RelWithDebInfo/testSFML




# For each target create a dummy ruleso the target does not have to exist
/Library/Frameworks/./sfml-graphics.framework/Versions/2.5.1/sfml-graphics:
/Library/Frameworks/./sfml-system.framework/Versions/2.5.1/sfml-system:
/Library/Frameworks/./sfml-window.framework/Versions/2.5.1/sfml-window:
