package com.example.graj.bt_connect;

import android.bluetooth.BluetoothAdapter;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    BluetoothAdapter BA;
    Intent BTenable;
    int request_code;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        BA = BluetoothAdapter.getDefaultAdapter();
        BTenable = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
        request_code = 1;
        if(BA == null)
        {
            Toast.makeText(getApplicationContext(),"Bluetooth not supported!",Toast.LENGTH_LONG).show();
        }
        else if(!BA.)
        {
            startActivityForResult(BTenable,request_code);
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        if(requestCode == request_code)
        {
            if(requestCode==RESULT_OK){
                Toast.makeText(getApplicationContext(),"Bluetooth On!",Toast.LENGTH_LONG).show();
            }
            else {
                if (resultCode == RESULT_CANCELED)
                {
                    Toast.makeText(getApplicationContext(),"Bluetooth running",Toast.LENGTH_LONG).show();
                }
            }
        }
    }
}
