import Welcome from "@/app/welcome";
import Settings from "@/app/settings";
import {createNativeStackNavigator} from "@react-navigation/native-stack";


export type RootStackParamList = {
    Welcome: undefined;
    Settings: undefined;
}

const Stack = createNativeStackNavigator<RootStackParamList>();


export default function Index() {
    return (
        <Stack.Navigator>
            <Stack.Screen name="Welcome" component={Welcome} />
            <Stack.Screen name="Settings" component={Settings} />
        </Stack.Navigator>
    );
}