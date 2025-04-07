import Welcome from "@/app/welcome";
import Settings from "@/app/settings";
import {createNativeStackNavigator} from "@react-navigation/native-stack";
import {useFonts} from "expo-font";
import {useEffect} from "react";
import * as SplashScreen from "expo-splash-screen";


export type RootStackParamList = {
    Welcome: undefined;
    Settings: undefined;
}

const Stack = createNativeStackNavigator<RootStackParamList>();

SplashScreen.preventAutoHideAsync();

export default function Index() {
    const [loaded, error] = useFonts({
        'Thesignature': require('../assets/fonts/Thesignature.ttf'),
    });
    useEffect(() => {
        if (loaded || error) {
            SplashScreen.hideAsync();
        }
    }, [loaded, error]);

    if(!loaded && !error) {
        return null;
    }

    return (
        <Stack.Navigator
            screenOptions={{
                headerShown: false
            }}
        >
            <Stack.Screen name="Welcome" component={Welcome} />
            <Stack.Screen name="Settings" component={Settings} />
        </Stack.Navigator>
    );
}