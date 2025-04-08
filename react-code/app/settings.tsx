import { Dimensions, SafeAreaView, Text, StyleSheet, TouchableOpacity, View} from "react-native";
import { useSharedValue } from "react-native-reanimated";
import Carousel, {
    ICarouselInstance,
    Pagination,
} from "react-native-reanimated-carousel";
import React from "react";
import Setting from "@/app/interface/setting-interface";
import {iterate} from "glob";

let data: Setting[] = [
    {
        colors: ["#ffffff", "#ff00ff", "#0000ff", "#000000", "#ffffff", "#ff00ff", "#0000ff", "#000000", "#ffffff", "#ff00ff", "#0000ff", "#000000", "#ffffff", "#ff00ff", "#0000ff", "#000000"],
        flashingPattern: "MOLD",
        direction: "outward",
        speed: 3,
    },
    {
        colors: ["#FF4D2E", "#2E8BFF", "#8A2EFF", "#FF2E8B", "#2EFF4D", "#4D2EFF", "#FF8A2E", "#2EFF8A", "#8B2EFF", "#FF2E4D", "#2E4DFF", "#4DFF2E", "#8AFF2E", "#2EFF4D", "#FF2E8A", "#4D8AFF"],
        flashingPattern: "TRACE ONE",
        direction: "inward",
        speed: 2,
    },
    {
        colors: ["#7B3F6D", "#1AE5FF", "#FF4C2B", "#28D47C", "#9B42F5", "#E6B800", "#4287F5", "#FF6B9C", "#2BFF8E", "#8E44AD", "#FF5733", "#3498DB", "#27AE60", "#E74C3C", "#9B59B6", "#F1C40F"],
        flashingPattern: "TECHNO",
        direction: "outward",
        speed: 3,
    }
];
let primKey: number[] = Array.from({ length: data.length }, (_, i) => i);
const width = Dimensions.get("window").width;
const height = Dimensions.get("window").height;

export default function Settings({navigation}: any) {
    const ref = React.useRef<ICarouselInstance>(null);
    const progress = useSharedValue<number>(0);
    const [currentIndex, setCurrentIndex] = React.useState(0);

    const onPressPagination = (index: number) => {
        ref.current?.scrollTo({
            count: index - progress.value,
            animated: true,
        });
    };

    // Read from file
    // for each item in data, push the index to primKey


    return (
        <SafeAreaView style={styles.container}>
            {/*Back Button*/}
            <View style={styles.backButton}>
            <TouchableOpacity style={styles.TO} onPress={() => navigation.navigate("Welcome")}>
                <Text style={{color: '#ffffff', textAlign: 'left', fontSize: 30}}>    ⟨    </Text>
            </TouchableOpacity>
            </View>



            <View style={styles.notBackButton}>
                {/*Title*/}
                <View style={{height: height * 2/10, justifyContent: "center", alignItems: "center"}}>
                    <Text style={styles.text}>Settings</Text>
                </View>


                {/*Carousel*/}
                <View style={{height: height / 2.5, borderStyle: "solid", borderWidth: 2, borderColor: "white", borderRadius: 7, justifyContent: "center", alignItems: "center"}}>
                    <View>
                        <Text style={{color: "white"}}>{data[currentIndex % data.length].flashingPattern}</Text>
                        <Text style={{color: "white"}}>{data[currentIndex % data.length].colors.toString()}</Text>
                        <Text style={{color: "white"}}>{data[currentIndex % data.length].direction}</Text>
                        <Text style={{color: "white"}}>{data[currentIndex % data.length].speed.toString()}</Text>
                    </View>
                </View>

                <View style={{ flex: 1, justifyContent: "center", alignItems: "center" }}>
                    <Carousel
                        ref={ref}
                        data={primKey}
                        width={width}
                        defaultIndex={0}
                        enabled={true}
                        onProgressChange={(offset, absoluteProgress) => {
                            progress.value = offset;
                            setCurrentIndex(Math.round(absoluteProgress));
                            console.log('Current focused item:', data[currentIndex]);
                        }}
                        renderItem={({item: item}:{ item: number }) => (
                            <View style={styles.renderItem}>
                                <Text style={{color: "white"}}>{data[item].flashingPattern}</Text>
                                <Text style={{color: "white"}}>{data[item].colors.toString()}</Text>
                                <Text style={{color: "white"}}>{data[item].direction}</Text>
                                <Text style={{color: "white"}}>{data[item].speed.toString()}</Text>
                            </View>
                        )}
                        mode="parallax"
                        style={{height: height * 2 /10, justifyContent: "center", alignItems: "center"}}
                    />

                </View>
            </View>
        </SafeAreaView>
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
        fontFamily: "Thesignature",
        fontSize: 130,
        color: "#ffffff",
    },
    backButton: {
        height: height / 10,
        width: "100%",
    },
    notBackButton: {
        height: "90%",
    },
    TO: {
    },
    renderItem: {
        borderStyle: "solid", borderWidth: 2, borderColor: "white", borderRadius: 7, width: width*9/10, height: "75%" , justifyContent: "center", alignItems: "center"
    }
});