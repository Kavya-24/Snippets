package com.ramanand.todolist;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ListView listView = (ListView) findViewById(R.id.listView);
        final EditText editText = (EditText) findViewById(R.id.editText);

        final ArrayList<String> todoItems = new ArrayList<String>();
        final ArrayAdapter<String> s;
        s = new  ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, todoItems);
        listView.setAdapter(s);

        editText.setOnKeyListener(new View.OnKeyListener(){
            public boolean onKey(View v, int keyCode, KeyEvent event){
                if(event.getAction() == KeyEvent.ACTION_DOWN)
                    if ((keyCode == KeyEvent.KEYCODE_DPAD_CENTER) ||
                            (keyCode == KeyEvent.KEYCODE_ENTER)){
                        todoItems.add(0, editText.getText().toString());
                        s.notifyDataSetChanged();
                        editText.setText("");
                        return true;
                    }
                return false;
            }
        });
    }
}