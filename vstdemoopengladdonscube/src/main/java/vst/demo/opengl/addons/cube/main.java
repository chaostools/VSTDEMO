package vst.demo.opengl.addons.cube;

import android.app.Activity;
import android.content.Context;
import android.graphics.Color;
import android.util.Log;
import android.view.View;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Keep;

// prevent optimizer from removing this class from classes*.dex

@Keep
public class main {
    NativeView n = null;
    Activity activity = null;
    Context context = null;

    public class MyListener implements View.OnClickListener {
        @Override
        public void onClick (View v) {
            Toast toast = Toast.makeText(context,
                    "This demo combines Java UI and native EGL + OpenGL renderer",
                    Toast.LENGTH_LONG);
            toast.show();
        }
    }

    public void onCreate(Activity mActivity, Context mContext) {
        if (activity == null) activity = mActivity;
        if (context == null) context = mContext;

        if (n == null) n = new NativeView(activity, context);

        Log.i(n.TAG, "onCreate()");

        // build layout
        RelativeLayout rel = new RelativeLayout(context);
        rel.addView(n.surfaceView);

        // set text
        TextView text = new TextView(context);
        text.setText("Hello World! Try clicking the screen");
        text.setTextSize(60f);
        text.setTextColor(Color.WHITE);
        rel.addView(text);

        // set layout
        activity.setContentView(rel);

        n.surfaceView.setOnClickListener(new MyListener());
    }

    public void onStart() {
        NativeView.nativeOnStart();
    }
    public void onResume() {
        NativeView.nativeOnResume();
    }
    public void onPause() {
        NativeView.nativeOnPause();
    }
    public void onStop() {
        NativeView.nativeOnStop();
    }
}
