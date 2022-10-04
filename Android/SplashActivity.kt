package com.example.authenticationdemo.ui

import android.content.Intent
import android.os.Bundle
import android.os.Handler
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.example.authenticationdemo.MainActivity
import com.example.authenticationdemo.R
import com.google.firebase.FirebaseApp
import com.google.firebase.auth.FirebaseAuth

class SplashActivity : AppCompatActivity() {

    private lateinit var auth: FirebaseAuth
    lateinit var handler: Handler
    lateinit var i: Intent
    val TAG = SplashActivity::class.java.simpleName

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_splash)

        FirebaseApp.initializeApp(this)

        auth = FirebaseAuth.getInstance()

        Log.e(TAG, auth.currentUser?.uid.toString() + auth.currentUser.toString())

        handler = Handler()
        handler.postDelayed({


            if (auth.currentUser?.uid == null) {
                i = Intent(this, SignInActivity::class.java)

            } else {
                i = Intent(this, MainActivity::class.java)

            }

            startActivity(i)
            finish()

        }, 1000)     //1 seconds delay


    }

    override fun onDestroy() {
        //Remove handlers
        super.onDestroy()

    }
}
