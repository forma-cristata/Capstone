import {Text, StyleSheet, SafeAreaView, Switch, TouchableOpacity} from "react-native";
import {SafeAreaProvider} from "react-native-safe-area-context";
import {useEffect, useState} from "react";
import { useFonts} from 'expo-font';
import * as SplashScreen from 'expo-splash-screen';

//SplashScreen.preventAutoHideAsync();
export default function Welcome({navigation}: any) {
    /*const [loaded, error] = useFonts({
        'Thesignature': require('../assets/fonts/Thesignature.ttf'),
    });
    useEffect(() => {
        if (loaded || error) {
            SplashScreen.hideAsync();
        }
    }, [loaded, error]);

    if(!loaded && !error) {
        return null;
    }*/

    function createButtonPressed() {
        navigation.navigate("Settings");
    }

    const [isEnabled, setIsEnabled] = useState(false);
    const toggleSwitch = () => setIsEnabled(previousState => !previousState);

    return (
        <SafeAreaProvider>
            <SafeAreaView style={styles.container}>
                <Text style={styles.text}>Hello</Text>
                <TouchableOpacity style={styles.button} onPress={createButtonPressed}>
                    <Text style={{color: '#ffffff', textAlign: 'center'}}>                Create               ⟩</Text>
                </TouchableOpacity>
                <Switch onValueChange={toggleSwitch} value={isEnabled}
                        trackColor={{false: '#665e73', true: '#ffffff'}}
                        thumbColor={isEnabled ? '#665e73' : '#f4f3f4'}
                        ios_backgroundColor="#3e3e3e"
                        style={styles.switch}/>
            </SafeAreaView>
        </SafeAreaProvider>
    );
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        alignItems: 'center',
        justifyContent: 'center',
        backgroundColor: '#000000',
    },
    text: {
        marginBottom: "30%",
        fontFamily: "Thesignature",
        fontSize: 130,
        color: "#ffffff",
    },
    button: {
        width: "50%",
        height: 40,
        borderRadius: 7,
        borderStyle: "solid",
        borderWidth: 2,
        borderColor: "#ffffff",
        backgroundColor: "#000000",
        marginBottom: "30%",
        alignItems: "center",
        justifyContent: "center",
    },
    switch: {},
});
