/**
 * Main Activity or the activty where we will have Navigation 
 */

//Top of file declarations
lateinit var drawer: DrawerLayout                                   //Drawer Layout of Activity
lateinit var navDrawerView: NavigationView                          //Mobile Navigation View
lateinit var mAppBarConfiguration: AppBarConfiguration              


private fun initNavDrawer() {

    drawer = findViewById<DrawerLayout>(R.id.main_drawer_layout)
    mAppBarConfiguration = AppBarConfiguration.Builder(
        R.id.menu_home,
        R.id.menu_bookmarks,
        R.id.menu_history,
        R.id.menu_suggest,
        R.id.menu_report_error
    ).setDrawerLayout(drawer)
        .build()

    //Ref to navigation View
    navDrawerView = findViewById(R.id.nav_drawer_view)

    //Create a navigation Graph
    val navControllerDrawer =
        Navigation.findNavController(this, R.id.nav_host_fragment)

    NavigationUI.setupActionBarWithNavController(
        this,
        navControllerDrawer,
        mAppBarConfiguration
    )

    NavigationUI.setupWithNavController(navDrawerView, navControllerDrawer)
}


/**
 * Activity Main Activity
 * Make sure that Drawer Layout is the parent of Navigation View
 */

<com.google.android.material.navigation.NavigationView
android:id="@+id/nav_drawer_view"
android:layout_width="wrap_content"
android:layout_height="match_parent"
android:layout_gravity="start"
android:background="@color/colorPrimary"
android:fitsSystemWindows="true"
app:headerLayout="@layout/header_layout"
app:menu="@menu/mobile_menu" />

