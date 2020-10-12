/**
 * Application Class
 */
class ApplicationUtilClass : Application() {

    companion object {

        lateinit var instance: ApplicationUtilClass


        fun getApplication(): ApplicationUtilClass {
            return instance
        }

        fun getContext(): Context {
            return instance.applicationContext
        }
    }

    override fun onCreate() {
        super.onCreate()

        instance = this
        AppCompatDelegate.setCompatVectorFromResourcesEnabled(true)


    }
}

/**
 * To get app context in non activity class use
 *  ApplicationUtilClass.getContext()
 */

 /**
  * Make sure to add the following in the manifest in the application tag
  */

 // android:name=".Utils.ApplicationUtil"
       