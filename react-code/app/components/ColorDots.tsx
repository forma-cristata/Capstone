import {View} from "react-native";


interface ColorProps {
    colors: string[],
}

const ColorDots = (props: ColorProps) => {
    return (
        <View style={{ flexDirection: "row" }}>
            {props.colors.map((color, index) => (
                <View
                    key={index}
                    style={{
                        width: 29,
                        height: 29,
                        backgroundColor: color,
                        borderRadius: "50%",
                        marginHorizontal: -3,
                    }}
                />
            ))}
        </View>
    );
};

export default ColorDots;