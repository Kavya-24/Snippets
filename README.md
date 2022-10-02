<hr>

<img src="https://user-images.githubusercontent.com/56113566/135768952-80f2a996-5aed-4938-9f3b-92b1d1747d86.png" height="300px">

<img src="https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=for-the-badge" alt="PRs Welcome" /> <a href="https://github.com/Kavya-24/Snippets/pulls" target="_blank"><img alt="GitHub pull requests" src="https://img.shields.io/github/issues-pr/Kavya-24/Snippets?style=for-the-badge" /></a> <a href="https://github.com/Kavya-24/Snippets/issues" target="_blank"><img alt="GitHub issues" src="https://img.shields.io/github/issues/Kavya-24/Snippets?style=for-the-badge" /></a> 


<details close>
<summary><h2 align="center">Project Tree Structure 📁</h2> </summary>


```

Snippets
│   CODE_OF_CONDUCT.md
│   CONTRIBUTING.md
│   README.md
│
├───.github
│       PULL_REQUEST_TEMPLATE.md
│
├───Algorithms
│   │   AVL TREES.txt
│   │   bresenham.py
│   │   Disjoint sets.txt
│   │   GreatCircleDistance.py
│   │   huffman-code.c
│   │   Kadane Algorithm.txt
│   │   KadaneAlgorithm.java
│   │   Krushals Min Cost Spanning Tree.txt
│   │   Overview.txt
│   │   Prefix Sum Algorithm.txt
│   │   Prim Min Spanning Tree.txt
│   │   SieveofEratosthenes_Algorithm.cpp
│   │   tic_tac_toe_game.cpp
│   │   Tower of Hanoi Recursion.txt
│   │   Trailingzeros.java
│   │
│   ├───2Pointer Algorithm
│   │       pairSum.cpp
│   │
│   ├───Dynamic Programming
│   │       01KnapsackProblem.cpp
│   │       EditDistance.cpp
│   │       LongestAlternatingSubsequence
│   │       Minimum number of jumps.cpp
│   │
│   ├───Hash
│   │       DoubleHashingC++.txt
│   │       Hash Table Class Chaining.txt
│   │       Hash Table Quadratic Probing.txt
│   │       HashTableLinearProbingC++.txt
│   │
│   ├───Mathematical Algorithms
│   │       Lucky Numbers
│   │
│   ├───Searching
│   │       Binary Search
│   │       Breadth First Search.txt
│   │       Depth First Search.txt
│   │       frequencyOf1.cpp
│   │       KMP algorithm.cpp
│   │       LinearSearch.cpp
│   │       matrixSearch.cpp
│   │       maximumInBitonic.cpp
│   │       Quicksort.java
│   │
│   └───Sorting Algorithms
│       ├───cpp
│       │       bogo_Sort.cpp
│       │       Bubble_Sorting.cpp
│       │       daa_topological sorting.cpp
│       │       heapSort.cpp
│       │       InsertionSort.cpp
│       │       IntersectionOfTwoSortedArrays.cpp
│       │       mergeSort.cpp
│       │       quickSort.cpp
│       │
│       ├───java
│       │       BogoSort.java
│       │       CyclicSort.java
│       │       Insertion_Sort.java
│       │       SleepSort.java
│       │       SlowSort.java
│       │
│       └───python
│               insertion_Sort.py
│               SlowSort.py
│
├───Android
│   │   appContext.kt
│   │   checkNetworkConnection.kt
│   │   initNavDrawer.kt
│   │   LoginScreen.xml
│   │   Overview.txt
│   │   recyclerViewAdapter.kt
│   │   RetrofitClient.kt
│   │   rvItemAnimator.kt
│   │   shareBitmapImage.kt
│   │   ThrowableErrorStatesRetrofit.kt
│   │
│   ├───CaveMan
│   │   │   .gitignore
│   │   │   build.gradle
│   │   │   gradle.properties
│   │   │   gradlew
│   │   │   gradlew.bat
│   │   │   README.md
│   │   │   SCORE.db
│   │   │   settings.gradle
│   │   │
│   │   ├───.idea
│   │   │       .gitignore
│   │   │       compiler.xml
│   │   │       encodings.xml
│   │   │       gradle.xml
│   │   │       jarRepositories.xml
│   │   │       misc.xml
│   │   │       runConfigurations.xml
│   │   │       vcs.xml
│   │   │
│   │   ├───app
│   │   │   │   .gitignore
│   │   │   │   build.gradle
│   │   │   │   google-services.json
│   │   │   │   proguard-rules.pro
│   │   │   │
│   │   │   └───src
│   │   │       ├───androidTest
│   │   │       │   └───java
│   │   │       │       └───com
│   │   │       │           └───example
│   │   │       │               └───caveman
│   │   │       │                       ExampleInstrumentedTest.java
│   │   │       │
│   │   │       ├───main
│   │   │       │   │   AndroidManifest.xml
│   │   │       │   │
│   │   │       │   ├───java
│   │   │       │   │   └───com
│   │   │       │   │       └───example
│   │   │       │   │           └───caveman
│   │   │       │   │               │   CreditsActivity.java
│   │   │       │   │               │   Fire.java
│   │   │       │   │               │   FullScreenImageDraw.java
│   │   │       │   │               │   GameActivity.java
│   │   │       │   │               │   GameBackground.java
│   │   │       │   │               │   GameRenderer.java
│   │   │       │   │               │   GameView.java
│   │   │       │   │               │   HelpActivity.java
│   │   │       │   │               │   HighscoresActivity.java
│   │   │       │   │               │   IActivity.java
│   │   │       │   │               │   LevelFinishImage.java
│   │   │       │   │               │   LevelParser.java
│   │   │       │   │               │   LevelSelect.java
│   │   │       │   │               │   MainActivity.java
│   │   │       │   │               │   OptionsActivity.java
│   │   │       │   │               │   Pipe.java
│   │   │       │   │               │   PlayerModel.java
│   │   │       │   │               │   ScoreDB.java
│   │   │       │   │               │   SplashScreenActivity.java
│   │   │       │   │               │   TextureLoader.java
│   │   │       │   │               │   UserInteract.java
│   │   │       │   │               │
│   │   │       │   │               ├───enemies
│   │   │       │   │               │       BasicEnemy.java
│   │   │       │   │               │       BonusEnemy.java
│   │   │       │   │               │       FireEnemy.java
│   │   │       │   │               │       JumpingEnemy.java
│   │   │       │   │               │       SimpleEnemy.java
│   │   │       │   │               │
│   │   │       │   │               └───hero
│   │   │       │   │                       Hero.java
│   │   │       │   │                       WeaponHandler.java
│   │   │       │   │
│   │   │       │   └───res
│   │   │       │       ├───anim
│   │   │       │       │       blink.xml
│   │   │       │       │       bounce.xml
│   │   │       │       │       clicked.xml
│   │   │       │       │       credits_animation.xml
│   │   │       │       │       fade_in.xml
│   │   │       │       │       fade_out.xml
│   │   │       │       │       move.xml
│   │   │       │       │       rotate.xml
│   │   │       │       │       sequential.xml
│   │   │       │       │       slide_down.xml
│   │   │       │       │       slide_up.xml
│   │   │       │       │
│   │   │       │       ├───anim-v4
│   │   │       │       │       slide_up.xml
│   │   │       │       │
│   │   │       │       ├───anim-v8
│   │   │       │       │       rotate.xml
│   │   │       │       │       sequential.xml
│   │   │       │       │
│   │   │       │       ├───drawable
│   │   │       │       │       .directory
│   │   │       │       │       about1.jpg
│   │   │       │       │       about_checked.png
│   │   │       │       │       about_unchecked.png
│   │   │       │       │       androidcave.png
│   │   │       │       │       arrow.png
│   │   │       │       │       arrow1.png
│   │   │       │       │       axe.png
│   │   │       │       │       axe_test2.png
│   │   │       │       │       bad_feedback.png
│   │   │       │       │       bg.png
│   │   │       │       │       bonus_enemy.png
│   │   │       │       │       caveman.png
│   │   │       │       │       click_button_checked.png
│   │   │       │       │       click_button_unchecked.png
│   │   │       │       │       credits1.png
│   │   │       │       │       creditsmusic_layout.xml
│   │   │       │       │       credits_checked.png
│   │   │       │       │       credits_unchecked.png
│   │   │       │       │       fire.png
│   │   │       │       │       fire_enemy.png
│   │   │       │       │       follow_button_checked.png
│   │   │       │       │       follow_button_unchecked.png
│   │   │       │       │       game_image.png
│   │   │       │       │       game_over.png
│   │   │       │       │       good_feedback.png
│   │   │       │       │       help1.png
│   │   │       │       │       helpmusic_layout.xml
│   │   │       │       │       help_checked.png
│   │   │       │       │       help_unchecked.png
│   │   │       │       │       highmusicbutton_layout.xml
│   │   │       │       │       highscore1.png
│   │   │       │       │       high_checked.png
│   │   │       │       │       high_unchecked.png
│   │   │       │       │       ic_launcher_background.xml
│   │   │       │       │       ic_music_off.xml
│   │   │       │       │       ic_music_on.xml
│   │   │       │       │       i_button_checked.png
│   │   │       │       │       i_button_unchecked.png
│   │   │       │       │       jump_enemy.png
│   │   │       │       │       level1.png
│   │   │       │       │       lvlbg1.png
│   │   │       │       │       lvlbg2.png
│   │   │       │       │       lvlbg3.png
│   │   │       │       │       lvlbg4.png
│   │   │       │       │       lvlbg5.png
│   │   │       │       │       lvlbg6.png
│   │   │       │       │       lvlbgclick1.png
│   │   │       │       │       lvlbgclick2.png
│   │   │       │       │       lvlbgclick3.png
│   │   │       │       │       lvlbgclick4.png
│   │   │       │       │       lvlbgclick5.png
│   │   │       │       │       lvlbgclick6.png
│   │   │       │       │       menuback.png
│   │   │       │       │       menuback1.png
│   │   │       │       │       next_level.png
│   │   │       │       │       option1.jpg
│   │   │       │       │       options_checked.png
│   │   │       │       │       options_unchecked.png
│   │   │       │       │       play1.png
│   │   │       │       │       play_checked.png
│   │   │       │       │       play_unchecked.png
│   │   │       │       │       rate.png
│   │   │       │       │       settings_button.png
│   │   │       │       │       share_button_checked.png
│   │   │       │       │       share_button_unchecked.png
│   │   │       │       │       splash.png
│   │   │       │       │       splash_background.png
│   │   │       │       │       start1.png
│   │   │       │       │       togglebutton_layout.xml
│   │   │       │       │       welcome.png
│   │   │       │       │
│   │   │       │       ├───drawable-v24
│   │   │       │       │       ic_launcher_foreground.xml
│   │   │       │       │
│   │   │       │       ├───font
│   │   │       │       │       luckiest_guy.xml
│   │   │       │       │
│   │   │       │       ├───layout
│   │   │       │       │       activity_main.xml
│   │   │       │       │       arrowbutton1_layout.xml
│   │   │       │       │       arrowbutton_layout.xml
│   │   │       │       │       badbutton_layout.xml
│   │   │       │       │       clickbutton_layout.xml
│   │   │       │       │       creditsbutton_layout.xml
│   │   │       │       │       credits_layout.xml
│   │   │       │       │       followbutton_layout.xml
│   │   │       │       │       gamebutton_layout.xml
│   │   │       │       │       goodbutton_layout.xml
│   │   │       │       │       helpbutton_layout.xml
│   │   │       │       │       help_layout.xml
│   │   │       │       │       highbutton_layout.xml
│   │   │       │       │       highscores_layout.xml
│   │   │       │       │       ibutton_layout.xml
│   │   │       │       │       i_layout.xml
│   │   │       │       │       level_select_layout.xml
│   │   │       │       │       lvl_button1.xml
│   │   │       │       │       lvl_button2.xml
│   │   │       │       │       lvl_button3.xml
│   │   │       │       │       lvl_button4.xml
│   │   │       │       │       lvl_button5.xml
│   │   │       │       │       lvl_button6.xml
│   │   │       │       │       menu_layout.xml
│   │   │       │       │       my_list.xml
│   │   │       │       │       optionsbutton_layout.xml
│   │   │       │       │       options_layout.xml
│   │   │       │       │       ratebutton_layout.xml
│   │   │       │       │       settingsbutton_layout.xml
│   │   │       │       │       sharebutton_layout.xml
│   │   │       │       │       splash.xml
│   │   │       │       │       welcomebutton_layout.xml
│   │   │       │       │
│   │   │       │       ├───mipmap-anydpi-v26
│   │   │       │       │       ic_launcher.xml
│   │   │       │       │       ic_launcher_round.xml
│   │   │       │       │
│   │   │       │       ├───mipmap-hdpi
│   │   │       │       │       ic_launcher.png
│   │   │       │       │       ic_launcher_round.png
│   │   │       │       │
│   │   │       │       ├───mipmap-mdpi
│   │   │       │       │       ic_launcher.png
│   │   │       │       │       ic_launcher_round.png
│   │   │       │       │
│   │   │       │       ├───mipmap-xhdpi
│   │   │       │       │       ic_launcher.png
│   │   │       │       │       ic_launcher_round.png
│   │   │       │       │
│   │   │       │       ├───mipmap-xxhdpi
│   │   │       │       │       ic_launcher.png
│   │   │       │       │       ic_launcher_round.png
│   │   │       │       │
│   │   │       │       ├───mipmap-xxxhdpi
│   │   │       │       │       ic_launcher.png
│   │   │       │       │       ic_launcher_round.png
│   │   │       │       │
│   │   │       │       ├───raw
│   │   │       │       │       bonus_enemy_sound.mp3
│   │   │       │       │       bstd.mp3
│   │   │       │       │       click.ogg
│   │   │       │       │       demo.mp4
│   │   │       │       │       fire_enemy_sound.mp3
│   │   │       │       │       gameover_sound_2.wav
│   │   │       │       │       hrach.ogg
│   │   │       │       │       music1.mp3
│   │   │       │       │       music11.mp3
│   │   │       │       │       music2.mp3
│   │   │       │       │       splash_background.mp3
│   │   │       │       │       wrongkill.mp3
│   │   │       │       │
│   │   │       │       ├───values
│   │   │       │       │       colors.xml
│   │   │       │       │       font_certs.xml
│   │   │       │       │       preloaded_fonts.xml
│   │   │       │       │       strings.xml
│   │   │       │       │       themes.xml
│   │   │       │       │
│   │   │       │       ├───values-night
│   │   │       │       │       themes.xml
│   │   │       │       │
│   │   │       │       └───xml
│   │   │       │               level1.xml
│   │   │       │               level2.xml
│   │   │       │               level3.xml
│   │   │       │               level4.xml
│   │   │       │               level5.xml
│   │   │       │               level6.xml
│   │   │       │
│   │   │       └───test
│   │   │           └───java
│   │   │               └───com
│   │   │                   └───example
│   │   │                       └───caveman
│   │   │                               ExampleUnitTest.java
│   │   │
│   │   ├───gradle
│   │   │   └───wrapper
│   │   │           gradle-wrapper.jar
│   │   │           gradle-wrapper.properties
│   │   │
│   │   └───images
│   │           1.jpg
│   │           10.jpg
│   │           11.jpg
│   │           12.jpg
│   │           13.jpg
│   │           14.jpg
│   │           15.jpg
│   │           16.jpg
│   │           17.jpg
│   │           18.jpg
│   │           19.jpg
│   │           2.jpg
│   │           20.jpg
│   │           21.jpg
│   │           22.jpg
│   │           23.jpg
│   │           3.jpg
│   │           4.jpg
│   │           5.jpg
│   │           6.jpg
│   │           7.jpg
│   │           8.jpg
│   │           9.jpg
│   │
│   └───flutter_foldable_sidebar_demo
│       │   .gitignore
│       │   .metadata
│       │   pubspec.lock
│       │   pubspec.yaml
│       │   README.md
│       │
│       ├───android
│       │   │   .gitignore
│       │   │   build.gradle
│       │   │   gradle.properties
│       │   │   settings.gradle
│       │   │
│       │   ├───app
│       │   │   │   build.gradle
│       │   │   │
│       │   │   └───src
│       │   │       ├───debug
│       │   │       │       AndroidManifest.xml
│       │   │       │
│       │   │       ├───main
│       │   │       │   │   AndroidManifest.xml
│       │   │       │   │
│       │   │       │   ├───kotlin
│       │   │       │   │   └───com
│       │   │       │   │       └───example
│       │   │       │   │           └───flutter_foldable_sidebar_demo
│       │   │       │   │                   MainActivity.kt
│       │   │       │   │
│       │   │       │   └───res
│       │   │       │       ├───drawable
│       │   │       │       │       launch_background.xml
│       │   │       │       │
│       │   │       │       ├───mipmap-hdpi
│       │   │       │       │       ic_launcher.png
│       │   │       │       │
│       │   │       │       ├───mipmap-mdpi
│       │   │       │       │       ic_launcher.png
│       │   │       │       │
│       │   │       │       ├───mipmap-xhdpi
│       │   │       │       │       ic_launcher.png
│       │   │       │       │
│       │   │       │       ├───mipmap-xxhdpi
│       │   │       │       │       ic_launcher.png
│       │   │       │       │
│       │   │       │       ├───mipmap-xxxhdpi
│       │   │       │       │       ic_launcher.png
│       │   │       │       │
│       │   │       │       └───values
│       │   │       │               styles.xml
│       │   │       │
│       │   │       └───profile
│       │   │               AndroidManifest.xml
│       │   │
│       │   └───gradle
│       │       └───wrapper
│       │               gradle-wrapper.properties
│       │
│       ├───assets
│       │       devs.jpg
│       │       powered_by.png
│       │       rps_logo.png
│       │
│       ├───ios
│       │   │   .gitignore
│       │   │
│       │   ├───Flutter
│       │   │       AppFrameworkInfo.plist
│       │   │       Debug.xcconfig
│       │   │       Release.xcconfig
│       │   │
│       │   ├───Runner
│       │   │   │   AppDelegate.swift
│       │   │   │   Info.plist
│       │   │   │   Runner-Bridging-Header.h
│       │   │   │
│       │   │   ├───Assets.xcassets
│       │   │   │   ├───AppIcon.appiconset
│       │   │   │   │       Contents.json
│       │   │   │   │       Icon-App-1024x1024@1x.png
│       │   │   │   │       Icon-App-20x20@1x.png
│       │   │   │   │       Icon-App-20x20@2x.png
│       │   │   │   │       Icon-App-20x20@3x.png
│       │   │   │   │       Icon-App-29x29@1x.png
│       │   │   │   │       Icon-App-29x29@2x.png
│       │   │   │   │       Icon-App-29x29@3x.png
│       │   │   │   │       Icon-App-40x40@1x.png
│       │   │   │   │       Icon-App-40x40@2x.png
│       │   │   │   │       Icon-App-40x40@3x.png
│       │   │   │   │       Icon-App-60x60@2x.png
│       │   │   │   │       Icon-App-60x60@3x.png
│       │   │   │   │       Icon-App-76x76@1x.png
│       │   │   │   │       Icon-App-76x76@2x.png
│       │   │   │   │       Icon-App-83.5x83.5@2x.png
│       │   │   │   │
│       │   │   │   └───LaunchImage.imageset
│       │   │   │           Contents.json
│       │   │   │           LaunchImage.png
│       │   │   │           LaunchImage@2x.png
│       │   │   │           LaunchImage@3x.png
│       │   │   │           README.md
│       │   │   │
│       │   │   └───Base.lproj
│       │   │           LaunchScreen.storyboard
│       │   │           Main.storyboard
│       │   │
│       │   ├───Runner.xcodeproj
│       │   │   │   project.pbxproj
│       │   │   │
│       │   │   ├───project.xcworkspace
│       │   │   │   │   contents.xcworkspacedata
│       │   │   │   │
│       │   │   │   └───xcshareddata
│       │   │   │           IDEWorkspaceChecks.plist
│       │   │   │           WorkspaceSettings.xcsettings
│       │   │   │
│       │   │   └───xcshareddata
│       │   │       └───xcschemes
│       │   │               Runner.xcscheme
│       │   │
│       │   └───Runner.xcworkspace
│       │       │   contents.xcworkspacedata
│       │       │
│       │       └───xcshareddata
│       │               IDEWorkspaceChecks.plist
│       │               WorkspaceSettings.xcsettings
│       │
│       ├───lib
│       │       custom_sidebar_drawer.dart
│       │       home_screen.dart
│       │       main.dart
│       │       splash_page.dart
│       │
│       └───test
│               widget_test.dart
│
├───Assembly Language
│       BubbleSort.asm
│       Merge Sort .asm
│       Overview
│       SelectionSortApplication.asm
│
├───C Language
│       Addition_Of_Two_Matrices.c
│       Alphabet_Triangle.c
│       Armstrong _Number.c
│       armstrong.c
│       Binary_Search.c
│       Bubble_Sort.c
│       Celsius_To_Fahrenheit.c
│       Converting_Number_Into_Characters.c
│       Counting_Sort.c
│       Decimal_To_Binary.c
│       Dijkstra_Algorithm.c
│       Fibonacci_Series.c
│       Finding_Missing_Number.c
│       G.C.D Using Recursion.c
│       Generating_Fibonacci_Triangle.c
│       Insertion_Sort.c
│       Interpolation_Search_With_Recursion.c
│       Kruskal's_Algorithm.c
│       Linear_Search.c
│       Matrix_Multiplication.c
│       Merge_Sort.c
│       multiplication_table_for_a_given_number.c
│       Number_Triangle.c
│       Overview.txt
│       Palindrome.c
│       PostTransition.c
│       Prime_Number.c
│       producer_consumer_problem.c
│       quadratic_eq.c
│       quicksort.c
│       Runge_Kutta_Method_For_First_Order_DE.c
│       Selection_Sort.c
│       Simple_Interest_Calculator.c
│       Styled_name_print.c
│       Two_complex_num_addition.c
│
├───Competitive programming template
│       template.cpp
│       template.kt
│
├───Data Structures
│   │   Overview.txt
│   │
│   ├───Array
│   │       Array_rotation.cpp
│   │       Equillibrium Point.cpp
│   │       LeadersInAnArray.cpp
│   │       MaximumMin.java
│   │       MissingNumber.java
│   │       Peak_element.cpp
│   │       SetMatrixZeros.java
│   │
│   ├───Binary Trees
│   │       IdenticalTrees.cpp
│   │       level_order_zigzag.cpp
│   │       SymmetricBinaryTree.cpp
│   │       verticle_print.cpp
│   │
│   ├───Graph
│   │       BFS code (matrix input).cpp
│   │
│   ├───Heap
│   │       Create Heap Using STL Vector.txt
│   │       Heap Sort.txt
│   │       Heapify_Faster_Method_to_CreateHeap_C++.txt
│   │
│   ├───LinkedList
│   │       Check if a loop exists in SLL.cpp
│   │       Delete a Linked List
│   │       Find kth node from last of a SLL.cpp
│   │       Find Middle Node of SLL.cpp
│   │       LinkedLists.c
│   │       Reverse a SLL.cpp
│   │
│   ├───Merge Sort
│   │       Merge Sort.cpp
│   │
│   ├───Recursion
│   │       generating_subset_string.cpp
│   │       rope_cutting.cpp
│   │       tower_of_hanoi.cpp
│   │
│   ├───Stack
│   │       BFS code (matrix input).cpp
│   │       Infix to Postfix.py
│   │       infix_to_postfix.cpp
│   │       ParanthesisChecker.cpp
│   │       postfixexpression_evaluation.py
│   │       Stack.c
│   │       StockSpan.cpp
│   │
│   └───Tree
│           AVL TREES.txt
│           Check_balanced.cpp
│           Left_view_print.cpp
│           Level_order_traversal_line_by_line.cpp
│           Max_Width_of_bt.cpp
│           Print_Left_View.cpp
│
├───Kotlin Extensions
│       Overview.txt
│
├───Machine Learning
│   │   .DS_Store
│   │   MulticlassClassification.ipynb
│   │   Overview.txt
│   │
│   ├───Face_Recognition
│   │   │   .DS_Store
│   │   │
│   │   ├───assets
│   │   │       face.jpg
│   │   │       haarcascade_frontalface_default.xml
│   │   │
│   │   └───model
│   │           Face_detection_using_OpenCV.ipynb
│   │
│   └───Super-Mario
│       │   mario.py
│       │   metriclogger.py
│       │   play.py
│       │   README.md
│       │   super mario.ipynb
│       │   wrapper.py
│       │
│       ├───src
│       │       proj_folder
│       │       stage-2.png
│       │       stage1-4.png
│       │
│       └───__pycache__
│               mario.cpython-38.pyc
│               metriclogger.cpython-38.pyc
│               wrapper.cpython-38.pyc
│
├───Project
│   └───Python
│       │   audio_translate.py
│       │   snake_game.py
│       │   speech_assistant.py
│       │   youtube_downloader.py
│       │
│       ├───dino_game
│       │   │   dino.py
│       │   │
│       │   └───assets
│       │       │   DinoWallpaper.png
│       │       │
│       │       ├───Bird
│       │       │       Bird1.png
│       │       │       Bird2.png
│       │       │
│       │       ├───Cactus
│       │       │       LargeCactus1.png
│       │       │       LargeCactus2.png
│       │       │       LargeCactus3.png
│       │       │       SmallCactus1.png
│       │       │       SmallCactus2.png
│       │       │       SmallCactus3.png
│       │       │
│       │       ├───Dino
│       │       │       DinoDead.png
│       │       │       DinoDuck1.png
│       │       │       DinoDuck2.png
│       │       │       DinoJump.png
│       │       │       DinoRun1.png
│       │       │       DinoRun2.png
│       │       │       DinoStart.png
│       │       │
│       │       └───Other
│       │               Chrome Dino.gif
│       │               Chrome Dino.mp4
│       │               Cloud.png
│       │               GameOver.png
│       │               Reset.png
│       │               Track.png
│       │
│       └───Hangman_game
│               hangman.py
│               words.py
│
├───Python
│   │   Arnold Cat Map.ipynb
│   │   Blur Algorithm.ipynb
│   │   defineaword.py
│   │   fibonacci.py
│   │   invisible cloak
│   │   Linkedin_automation.py
│   │   LogisticRegression.ipynb
│   │   PIL Scramble Image.ipynb
│   │   Staircase.py
│   │   Video_Scrambler.ipynb
│   │   WhatsApp_automation.py
│   │
│   ├───CNN Architectures
│   │       Alexnet in Pytorch.ipynb
│   │       Alexnet_architecture.png
│   │       CIFAR-10 Pytorch.ipynb
│   │       CNN Pytorch.ipynb
│   │       GoogLeNet PyTorch.ipynb
│   │       GoogLeNet_architecture.png
│   │       LeNet Pytorch.ipynb
│   │       LeNet_architecture.png
│   │       MNIST Pytorch.ipynb
│   │       NiN PyTorch.ipynb
│   │       NIN_architecture.png
│   │       Pretrained Pytorch.ipynb
│   │       Resnet in PyTorch.ipynb
│   │       ResNet_VGG_architecture.png
│   │       VGG in PyTorch.ipynb
│   │
│   └───Ensemble learning methods
│       │   AdaBoost.ipynb
│       │   Random_Forest.ipynb
│       │
│       └───.ipynb_checkpoints
│               AdaBoost-checkpoint.ipynb
│               Random_Forest-checkpoint.ipynb
│
├───UI Models
│       Overview.txt
│
└───Web development
    │   Overview.txt
    │
    ├───BMI Calculator
    │       app.js
    │       index.html
    │       styles.css
    │
    ├───Colour Changer
    │       index.html
    │       main.js
    │
    ├───CSS
    │       ButtonAnimation.html
    │       Loading_Effect.html
    │
    ├───JS
    │       asyncawait.js
    │
    ├───notes_app
    │       app.js
    │       index.html
    │
    └───Website Project
            index.html
            script.js
            style.css
            wesbite.md

```

</details>

</details>

<h2 align="center"> Project Admin 👩‍💻</h2>

<p align="center"><a href="https://github.com/Kavya-24" ><img align ="center" src="https://avatars.githubusercontent.com/u/54931749?v=4" width=150px height=150px /></a></p>      
                                                                        
<h2 align="center">✨ Special Thanks To Contributors ✨</h2>

<p align="center">
 
 <a href="https://github.com/Kavya-24/Snippets/graphs/contributors">
 <img src="https://contrib.rocks/image?repo=Kavya-24/Snippets" />

</p> 

<hr>
